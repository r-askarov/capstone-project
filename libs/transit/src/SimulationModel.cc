#include "SimulationModel.h"

#include "DroneFactory.h"
#include "PackageFactory.h"
#include "RobotFactory.h"
#include "HumanFactory.h"
#include "HelicopterFactory.h"
#include "ChargingStationFactory.h"
#include "math/vector3.h"
#include "limits.h"

SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  entityFactory.AddFactory(new DroneFactory());
  entityFactory.AddFactory(new PackageFactory());
  entityFactory.AddFactory(new RobotFactory());
  entityFactory.AddFactory(new HumanFactory());
  entityFactory.AddFactory(new HelicopterFactory());
  entityFactory.AddFactory(new ChargingStationFactory());
}

SimulationModel::~SimulationModel() {
  // Delete dynamically allocated variables
  for (auto& [id, entity] : entities) {
    delete entity;
  }
  delete graph;
}

IEntity* SimulationModel::createEntity(JsonObject& entity) {
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;

  IEntity* myNewEntity = nullptr;

  // Spawn charging stations
  if (name.compare("ChargingStation") == 0) {
    Vector3 randomPos;
    for (int i = 0; i < 15; i++) {
      myNewEntity = nullptr;
      if (myNewEntity = entityFactory.CreateEntity(entity)) {
        randomPos.x = ((static_cast<float>(rand())) / RAND_MAX) * (2900) - 1400;
        randomPos.y = 250;
        randomPos.z = ((static_cast<float>(rand())) / RAND_MAX) * (1600) - 800;
        myNewEntity->setPosition(randomPos);
        myNewEntity->linkModel(this);
        controller.addEntity(*myNewEntity);
        entities[myNewEntity->getId()] = myNewEntity;
      }
    }
    return myNewEntity;
  }

  // Spawn any other entity
  if (myNewEntity = entityFactory.CreateEntity(entity)) {
    // Call AddEntity to add it to the view
    myNewEntity->linkModel(this);
    controller.addEntity(*myNewEntity);
    entities[myNewEntity->getId()] = myNewEntity;
  }

  return myNewEntity;
}

void SimulationModel::removeEntity(int id) {
  removed.insert(id);
}

/// Schedules a Delivery for an object in the scene
void SimulationModel::scheduleTrip(JsonObject& details) {
  std::string name = details["name"];
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  Robot* receiver = nullptr;

  for (auto& [id, entity] : entities) {
    if (name == entity->getName()) {
      if (Robot* r = dynamic_cast<Robot*>(entity)) {
        if  (r->requestedDelivery) {
          receiver = r;
          break;
        }
      }
    }
  }

  Package* package = nullptr;

  for (auto& [id, entity] : entities) {
    if (name + "_package" == entity->getName()) {
      if (Package* p = dynamic_cast<Package*>(entity)) {
        if  (p->requiresDelivery) {
          package = p;
          break;
        }
      }
    }
  }

  if (receiver && package) {
    package->initDelivery(receiver);
    std::string strategyName = details["search"];
    package->setStrategyName(strategyName);
    scheduledDeliveries.push_back(package);
    controller.sendEventToView("DeliveryScheduled", details);
  }
}

const routing::IGraph* SimulationModel::getGraph() {
  return graph;
}

/// Updates the simulation
void SimulationModel::update(double dt) {
  for (auto& [id, entity] : entities) {
    entity->update(dt);
    controller.updateEntity(*entity);
  }
  for (int id : removed) {
    removeFromSim(id);
  }
  removed.clear();
}

void SimulationModel::stop(void) {
  controller.stop();
}

void SimulationModel::removeFromSim(int id) {
  IEntity* entity = entities[id];
  if (entity) {
    for (auto i = scheduledDeliveries.begin();
      i != scheduledDeliveries.end(); ++i) {
      if (*i == entity) {
        scheduledDeliveries.erase(i);
        break;
      }
    }
    controller.removeEntity(*entity);
    entities.erase(id);
    delete entity;
  }
}

std::map<int, IEntity*> SimulationModel::getEntities() {
  return this->entities;
}

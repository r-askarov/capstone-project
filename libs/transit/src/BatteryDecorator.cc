#include "BatteryDecorator.h"
#include "math/vector3.h"
#include "BeelineStrategy.h"
#include "SimulationModel.h"
#include "Package.h"
#include "limits.h"

BatteryDecorator::BatteryDecorator(Drone* drone) {
    this->drone = drone;
    this->details = drone->getDetails();
    this->batteryLevel = 100.0;
    this->isCharging = false;
}

BatteryDecorator::~BatteryDecorator() {
    delete this->drone;
    delete this->toStation;
}

void BatteryDecorator::decreaseBatteryLevel(double dt) {
    this->batteryLevel -= 0.7 * dt;
}

void BatteryDecorator::charge(double dt) {
    this->batteryLevel += mutliplier * dt;
}

bool BatteryDecorator::fullyCharged() {
    return this->batteryLevel >= 100;
}

Vector3 BatteryDecorator::findNearestChargingStation() {
    float minDistance = 9999999;
    Vector3 nearestChargingStationPosition = Vector3(0, 0, 0);
    for (auto& [id, entity] : this->model->getEntities()) {
        if (entity->getName() == "ChargingStation") {
            float currentDist = this->drone->getPosition()
            .dist(entity->getPosition());
            if (currentDist < minDistance) {
                minDistance = currentDist;
                nearestChargingStationPosition = entity->getPosition();
            }
        }
    }
    // to land right on top of the charging platform
    nearestChargingStationPosition.y += 40;
    return nearestChargingStationPosition;
}

void BatteryDecorator::linkModel(SimulationModel* model) {
    this->model = model;
    this->drone->linkModel(model);
}

bool BatteryDecorator::inMiddleOfDropOff() {
    if (!drone->getPackage() && !drone->getPickedUp()) {
        return false;
    }
    float distFromDest = this->getPosition().dist
    (drone->getPackage()->getDestination());
    bool deliveryCompleted = this->drone->movementStrategyCompleted();
    return distFromDest <= 30 && !deliveryCompleted;
}

void BatteryDecorator::update(double dt) {
    std::cout << batteryLevel << std::endl;
    if (isCharging) {
        if (this->fullyCharged()) {
            this->drone->update(dt);
            if (drone->getAvailability()) {
                return;
            }
            isCharging = false;
            this->toStation = nullptr;
        } else {
            this->charge(dt);
        }
    } else if (batteryLevel <= 20 && batteryLevel > 0) {
        // If threshold reached mid drop-off, complete delivery and go charge
        while (inMiddleOfDropOff()) {
            this->drone->update(dt);
            this->setPosition(this->drone->getPosition());
            this->setDirection(this->drone->getDirection());
            decreaseBatteryLevel(dt);
        }
        if (toStation == nullptr) {
            this->toStation = new BeelineStrategy(this->getPosition(),
            findNearestChargingStation());
        }

        this->toStation->move(this->drone, dt);
        this->setPosition(this->drone->getPosition());
        this->setDirection(this->drone->getDirection());
        if (drone->getPackage() && drone->getPickedUp()) {
            drone->getPackage()->setPosition(this->drone->getPosition());
            drone->getPackage()->setDirection(this->drone->getDirection());
        }
        decreaseBatteryLevel(dt);

        if (this->toStation->isCompleted()) {
            mutliplier = 7;
            isCharging = true;
        }
    } else if (batteryLevel <= 0) {  // Slower Solar Charging
        mutliplier = 3;
        isCharging = true;
    } else {
        this->drone->update(dt);
        this->setPosition(this->drone->getPosition());
        this->setDirection(this->drone->getDirection());
        decreaseBatteryLevel(dt);
    }
}

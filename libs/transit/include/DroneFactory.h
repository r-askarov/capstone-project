#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Drone.h"

/**
 *@brief Drone Factory class to produce Drone objects
 **/
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor where dynamically-allocated memory is freed
   **/
  virtual ~DroneFactory() {}

  /**
   * @brief Creation function which creates a drone using 
   * the given JSON object
   * @param entity - JsonObject to be used to create the new drone entity
   * @return Entity that was created if it was created successfully, or a
   * nullpointer if it wasn't
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif

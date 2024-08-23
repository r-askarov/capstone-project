#ifndef CHARGING_STATION_FACTORY_H_
#define CHARGING_STATION_FACTORY_H_

#include "IEntityFactory.h"
#include "ChargingStation.h"

/**
 * @brief Charging Station Factory to produce ChargingStation objects
 **/
class ChargingStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates the entity using the given JSON object
   * @param entity - JsonObject to be used to create the new entity
   * @return Entity that was created if it was created successfully, or a
   * nullpointer if creation failed
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif

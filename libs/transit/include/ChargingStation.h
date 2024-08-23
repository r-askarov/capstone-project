#ifndef CHARGING_STATION_H_
#define CHARGING_STATION_H_

#include "IEntity.h"

/** 
 * @brief Represents a ChargingStation in a physical system.
 * Charging staions are static and do not move
*/
class ChargingStation : public IEntity {
 public:
  /**
   * @brief Construct a ChargingStation object based on JSON data
   * @param obj JSON object containing the desired ChargingStation's data
   */
  ChargingStation(JsonObject& obj);
  /**
   * @brief overriding IEntity's pure virtual 'update' function,
   * a ChargingStation entity does not move though
   * @param dt delta time
   */
  void update(double dt);
};

#endif

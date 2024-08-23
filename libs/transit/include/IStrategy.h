#ifndef I_STRATEGY_H_
#define I_STRATEGY_H_

#include "IEntity.h"

/**
 * @brief Strategy interface
 * This class defines the interface for strategies which will determine
 * movement of entities within the simulation.
 */ 
class IStrategy {
 public:
 /**
  * @brief Move entity toward next position in its path
  * @param entity Entity to move
  * @param dt Delta Time
  */
  virtual void move(IEntity* entity, double dt) = 0;

  /**
   * @brief Check if the trip is completed
   * @return true if complete, false if not
   */
  virtual bool isCompleted() = 0;
};

#endif

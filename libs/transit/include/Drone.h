#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

class Package;

// Represents a drone in a physical/simulated system.
// Drones move using a specified velocity and direction
/**
 * @class Drone
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction
 */
class Drone : public IEntity {
 public:
  /**
   * @brief Drones are created by labeling them with a name
   * @param obj JSON object containing the drone's information
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor where dynamically-allocated memory is freed
   */
  ~Drone();


  /**
   * @brief Gets the next delivery in the scheduler
   */
  void getNextDelivery();

  /**
   * @brief Updates the drone's position
   * @param dt Delta time, which is extensively used to calculate different speeds
   */
  void update(double dt);

  /**
   * @return pointer to drone's package
   */
  Package* getPackage();

  /**
   * @brief Indicate whether the drone is available or not
   * @return true if drone is available, false if not
   */
  bool getAvailability();

  /**
   * @return true if package is picked up by drone, false if not
   */
  bool getPickedUp();

   /**
   * @return true if the final dest. strategy has completed i.e. the delivery
   * is completed, false if not
   */
  bool movementStrategyCompleted();

  /**
   * @brief Removing the copy constructor operator
   * so that drones cannot be copied
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied
   */
  Drone& operator=(const Drone& drone) = delete;

 private:
  bool available = false;
  bool pickedUp = false;
  Package* package = nullptr;
  IStrategy* toPackage = nullptr;
  IStrategy* toFinalDestination = nullptr;
};

#endif

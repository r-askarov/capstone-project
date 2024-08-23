#ifndef BATTERY_DECORATORH_
#define BATTERY_DECORATORH_

#include "IEntity.h"
#include "IStrategy.h"
#include "Drone.h"

/** 
 * @brief BatteryDecorator class
 * This decorating class implements the necessary logic for 
 * battery functionality for wrapped Drone objects
*/
class BatteryDecorator : public IEntity {
 public:
    /**
     * @brief BatteryDecorator Constructor, sets initial battery to 100%
     * @param drone pointer to the drone object to be decorated
    */
    BatteryDecorator(Drone* drone);

    /**
     * @brief BatteryDecorator Destructor
     * Deletes memory associated with dynamically allocated private variables
    */
    ~BatteryDecorator();

    /**
     * @brief Decreases battery level with respect to dt
     * @param dt delta time
    */
    void decreaseBatteryLevel(double dt);

    /**
     * @brief Charges battery, increasing battery level with respect to dt
     * @param dt delta time
    */
    void charge(double dt);

    /**
     * @brief Returns a boolean indicating whether the battery is fully charged
     * @return true if batteryLevel == 100, false otherwise
    */
    bool fullyCharged();

    /**
     * @brief Overrides IEntity's linkModel
     * to also link the wrapped drone to the model
    */
    void linkModel(SimulationModel* model);

    /**
     * @brief Find the nearest charging station to the drone
     * @return Vector3 representing the position of the nearest station
    */
    Vector3 findNearestChargingStation();

   /**
    * @brief Indicate whether the drone is 
    * in the middle of the drop off process (includes celebration)
    * @return true if drone is still dropping off package, false if not
    */
    bool inMiddleOfDropOff();

    /**
     * @brief Updates the drone's position and handles the delivery logic of 
       the drone with the additional battery functionality 
       implemented in this class
     * @param dt delta time
    */
    void update(double dt);

 private:
    Drone* drone = nullptr;
    IStrategy* toStation = nullptr;
    float batteryLevel;
    float mutliplier = 1;
    bool isCharging;
};

#endif

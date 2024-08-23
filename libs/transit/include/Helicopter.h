#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"

/** 
 * @brief Represents a Helicopter in a physical system
 * A Helicopter randomly moves in the sky using Beeline
*/
class Helicopter : public IEntity {
 public:
  /**
   * @brief Construct a Helicopter object based on JSON data
   * @param obj JSON object containing the desired Helicopter's data
   */
  Helicopter(JsonObject& obj);
  /**
   * @brief destructor where we dynamically allocated memory is freed
   */
  ~Helicopter();
  /**
   * @brief updates the helicopter's position
   * @param dt delta time
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif

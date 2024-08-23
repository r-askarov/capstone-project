#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"

/** 
 * @brief Human Entity class
 * @brief Represents a human in a physical system
 * Humans move randomly throughout the simulation using A*
*/
class Human : public IEntity {
 public:
  /**
   * @brief Construct a Human object based on given JSON data
   * @param obj JSON object containing the human's data
   */
  Human(JsonObject& obj);
  /**
   * @brief Destructor where dynamically-allocated memory is freed
   **/
  ~Human();
  /**
   * @brief updates the Human's position
   * @param dt delta time
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif

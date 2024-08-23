#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include "ICelebrationDecorator.h"

/**
 * @brief JumpDecorator class
 * This decorating class implements a jump celebration 
 * by wrapping IStrategy objects.
 */
class JumpDecorator : public ICelebrationDecorator {
 public:
  /**
   * @brief Construct a Jump Decorator object
   * @param strategy the strategy to decorate onto
   * @param time how long to celebrate
   * @param jumpHeight how far up to jump
   */
  JumpDecorator(IStrategy* strategy, double time = 4, double jumpHeight = 10);

  /**
   * @brief Make the entity celebrate with the jump behavior.
   * @param entity Entity to celebrate
   * @param dt Delta Time
   */
  void celebrate(IEntity* entity, double dt);

 private:
  double jumpHeight = 10;
  bool up = true;
  double h = 0;
};

#endif  // JUMP_DECORATOR_H_

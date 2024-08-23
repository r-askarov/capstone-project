#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include "ICelebrationDecorator.h"

/**
 * @brief SpinDecorator class
 * This decorating class implements a spin celebration 
 * by wrapping IStrategy objects.
 */
class SpinDecorator : public ICelebrationDecorator {
 public:
  /**
   * @brief Construct a Spin Decorator object
   * @param strategy the strategy to decorate onto
   * @param time how long to celebrate
   * @param spinSpeed multiplier for how fast to spin
   */
  SpinDecorator(IStrategy* strategy, double time = 4, double spinSpeed = 1);

  /**
   * @brief Make an entity celebrate with the spin behavior
   * @param entity Entity to celebrate with
   * @param dt Delta Time
   */
  void celebrate(IEntity* entity, double dt);

 private:
  double spinSpeed = 1;
};

#endif  // SPIN_DECORATOR_H_

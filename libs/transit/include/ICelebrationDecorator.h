#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include "IStrategy.h"

/**
 * @brief Celebration Decorator Interface class
 * This class defines the interface for decorator classes
 * which wrap PathStrategy objects to add celebrations once they are completed.
 **/
class ICelebrationDecorator : public IStrategy {
 protected:
  IStrategy* strategy = nullptr;
  float time = 0;

 public:
  /**
   * @brief Construct a Celebration Decorator object
   * @param strategy the strategy to decorate onto
   * @param time how long to celebrate, which is default to be 4 seconds
   */
  ICelebrationDecorator(IStrategy* strategy, double time = 4);

  /**
   * @brief Destructor where dynamically-allocated memory is freed.
   */
  virtual ~ICelebrationDecorator();

  /**
   * @brief Move the entity, with the added celebration behavior when necessary.
   * @param entity Entity to move
   * @param dt delta time
   */
  virtual void move(IEntity* entity, double dt);

  /**
   * @brief Check if celebration is completed by checking the time elapsed.
   * A celebration is considered completed if it has lasted 4 or more seconds.
   * @return true if celebration has completed, false if not
   */
  virtual bool isCompleted();

  /**
   * @brief Pure virtual function where celebrations
   * will be implemented by child classes.
   * @param entity entity that should celebrate
   * @param dt delta time
   */
  virtual void celebrate(IEntity* entity, double dt) = 0;
};

#endif  // CELEBRATION_DECORATOR_H_

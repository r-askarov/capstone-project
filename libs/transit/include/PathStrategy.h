#ifndef PATH_STRATEGY_H_
#define PATH_STRATEGY_H_

#include "IStrategy.h"

/**
 * @brief PathStrategy class
 * A PathStrategy object is used to assign a movement mechanism
 * to entities and perform their movement across the map
 */
class PathStrategy : public IStrategy {
 protected:
  std::vector<std::vector<float>> path;
  int index;

 public:
  /**
   * @brief Construct a PathStrategy object
   * @param path the path to follow
   */
  PathStrategy(std::vector<std::vector<float>> path = {});

  /**
   * @brief Move toward next position in the path
   * @param entity Entity to move
   * @param dt Delta Time
   */
  virtual void move(IEntity* entity, double dt);

  /**
   * @brief Check if the trip is completed i.e. reached end of path
   * @return true if complete, false if not
   */
  virtual bool isCompleted();
};

#endif  // PATH_STRATEGY_H_

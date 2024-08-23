#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

#include "PathStrategy.h"
#include "graph.h"

/**
 * @brief DFS strategy class 
 * This class implements DFS in order to 
 * find a path for movement across the map
 */
class DfsStrategy : public PathStrategy {
 public:
  /**
   * @brief Construct a DFS Strategy object.
   * performs DFS on a given graph and sets the path variable
   * from PathStrategy to the path found
   * @param position Beginning position coordinates
   * @param destination Desired destination coordinates
   * @param graph the graph to perform DFS on
   */
  DfsStrategy(Vector3 position, Vector3 destination,
              const routing::IGraph* graph);
};
#endif  // DFS_STRATEGY_H_

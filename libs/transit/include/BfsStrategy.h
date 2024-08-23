#ifndef BFS_STRATEGY_H_
#define BFS_STRATEGY_H_

#include "PathStrategy.h"
#include "graph.h"

/**
 * @brief BFS strategy class 
 * This class implements BFS in order to 
 * find a path for movement across the map
 */
class BfsStrategy : public PathStrategy {
 public:
    /**
    * @brief Construct a BFS Strategy object.
   * performs BFS algorithm on the given graph and sets the path variable
   * from PathStrategy to the path found
    * @param start beginning point coordinates on the graph
    * @param destination desired destination point coordinates on the graph
    * @param graph the graph to perform BFS on
    **/
  BfsStrategy(Vector3 position, Vector3 destination,
              const routing::IGraph* graph);
};
#endif  // BFS_STRATEGY_H_

#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

#include "PathStrategy.h"
#include "graph.h"

/**
 * @brief A* strategy class 
 * This class implements A* in order to 
 * find a path for movement across the map
 */
class AstarStrategy : public PathStrategy {
 public:
    /**
    * @brief Construct a A* strategy object.
    * performs A* on the given graph and sets the path variable
    * from PathStrategy to the path found
    * @param start beginning point coordinates on the graph
    * @param destination desired destination point coordinates on the graph
    * @param graph the graph to perform A* on
    **/
  AstarStrategy(Vector3 position, Vector3 destination,
                const routing::IGraph* graph);
};
#endif  // ASTAR_STRATEGY_H_

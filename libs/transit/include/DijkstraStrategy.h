#ifndef DIJKSTRA_STRATEGY_H_
#define DIJKSTRA_STRATEGY_H_

#include "PathStrategy.h"
#include "graph.h"

/**
 * @brief Dijkstra strategy class 
 * This class implements Dijkstra's algorithm in order to 
 * find a path for movement across the map
 */
class DijkstraStrategy : public PathStrategy {
 public:
  /**
   * @brief Construct a Dijkstra Strategy object.
   * performs Dijkstra's algorithm on the given graph and sets the path variable
   * from PathStrategy to the path found
   * @param position beginning position coordinates
   * @param destination desired destination coordinates
   * @param graph the graph to perform Dijkstra's on
   */
  DijkstraStrategy(Vector3 position, Vector3 destination,
                   const routing::IGraph* graph);
};
#endif  // DIJKSTRA_STRATEGY_H_

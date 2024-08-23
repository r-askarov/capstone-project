#ifndef BEELINE_H_
#define BEELINE_H_

#include "PathStrategy.h"

/**
 * @brief Beeline strategy class 
 * This class implements beeline in order to 
 * find a path for movement across the map
 */
class BeelineStrategy : public PathStrategy {
 public:
    /**
    * @brief Construct a Beeline Strategy object.
   * performs Beeline algorithm on a given graph and sets the path variable
   * from PathStrategy to the path found
    * @param start beginning point coordinates on the graph
    * @param destination desired destination point coordinates on the graph
    **/
    BeelineStrategy(Vector3 pos, Vector3 des);
};

#endif  // BEELINE_H_

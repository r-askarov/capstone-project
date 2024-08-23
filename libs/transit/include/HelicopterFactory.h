#ifndef Helicopter_FACTORY_H_
#define Helicopter_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Helicopter.h"

/**
 * @brief Helicopter Factory to produce Helicopter objects
 **/
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor where dynamically-allocated memory is freed
   **/
  virtual ~HelicopterFactory() {}

  /**
   * @brief Creates entity using the given JSON object
   * @param entity - JsonObject to be used to create the new entity
   * @return Entity that was created if it was created successfully, or a
   * nullpointer if creation failed
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif

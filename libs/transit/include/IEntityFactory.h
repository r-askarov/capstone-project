#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "IEntity.h"
#include "util/json.h"

/**
 * @brief IEntityFactory Interface
 * This class defines the interface for factory classes that create entities
 **/
class IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~IEntityFactory() {}

  /**
   * @brief Pure virutal, creates entity using the given JSON object
   * @param entity - JsonObject to be used to create the new entity
   * @return Entity that was created if it was created successfully, or a
   * nullpointer if creation failed
   **/
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif

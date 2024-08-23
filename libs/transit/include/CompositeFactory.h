#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief CompositeFactory class
 * This class implements the composite pattern for the factory pattern,
 * which is helpful when there are operations that we want to perform on a 
 * group of the same type of objects, such as creation of different entities
 **/
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates entity using the given JSON object.
   * @param entity - object of type JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   * nullpointer if it wasn't correctly made.
   **/
  IEntity* CreateEntity(JsonObject& entity);

  /**
   * @brief Adds a given factory to the componentFactories vector
   * @param factoryEntity Factory to add
   **/
  void AddFactory(IEntityFactory* factoryEntity);

  /**
   * @brief Destructor which deletes dynamically-allocated
   * items in componentFactories
   **/
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif

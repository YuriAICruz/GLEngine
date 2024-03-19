#include "Entity.h"

#include "Component.h"

namespace Gly
{
    void Entity::addComponent(std::shared_ptr<Component> component)
    {
        components.push_back(std::move(component));
    }
}

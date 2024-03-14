#pragma once
#include "framework.h"
#include <memory>
#include <vector>

namespace Gly
{
    class Component;

    class GLY_API Entity
    {
    private:
        std::vector<std::shared_ptr<Component>> components;

    public:
        void update();
        void fixedUpdate();

        void addComponent(std::shared_ptr<Component> component);
        void removeComponent();

        template <typename T>
        T* getComponent() const
        {
            for (const std::shared_ptr<Component>& component : components)
            {
                if (T* derived = dynamic_cast<T*>(component.get()))
                {
                    return derived;
                }
            }

            return nullptr;
        }
    };
}

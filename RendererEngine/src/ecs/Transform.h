#pragma once
#include "../framework.h"
#include "Component.h"
#include "../Vector3.h"

namespace Gly
{
    class GLY_API Transform : public Component
    {
    public:
        Vector3 position;
        Vector3 rotation;//?
        Vector3 scale;
    };
}

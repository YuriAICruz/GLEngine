﻿#pragma once
#include "framework.h"

namespace Gly
{
    struct GLY_API Vector3
    {
    public:
        Vector3() = default;

        Vector3(int x, int y, int z) : x(x), y(y), z(z)
        {
        }

        float x;
        float y;
        float z;
    };
}

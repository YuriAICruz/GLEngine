#pragma once

namespace Gly
{
    struct Vector3
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

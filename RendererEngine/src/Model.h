#pragma once
#include <vector>

#include "Material.h"
#include "Vector3.h"

namespace Gly
{
    class Model
    {
    private:
        Material& material;
        std::vector<float> vertices;
        std::vector<int> triangles;
        Vector3 position;
        Vector3 scale;
        unsigned int buffer;

    public:
        Model(const std::vector<float>& vertices, const std::vector<int>& triangles, Vector3 position, Vector3 scale, Material& mat) :
            material(mat),
            vertices(vertices),
            triangles(triangles),
            position(position),
            scale(scale)
        {
        }

        void generateBuffer();
    };
}

#pragma once
#include <vector>

#include "Material.h"
#include "Vector3.h"

namespace Gly
{
    class Model
    {
    private:
        unsigned int vertexDataCount = 3;
        Material& material;
        std::vector<float> vertices;
        std::vector<unsigned int> triangles;
        Vector3 position;
        Vector3 scale;
        unsigned int buffer;
        unsigned int indexBuffer;

    public:
        Model(const std::vector<float>& vertices, const std::vector<unsigned int>& triangles, Vector3 position, Vector3 scale, Material& mat) :
            material(mat),
            vertices(vertices),
            triangles(triangles),
            position(position),
            scale(scale)
        {
        }

        void generateBuffer();
        void render();
    };
}

#pragma once
#include "framework.h"
#include "graphics/Material.h"
#include "Vector3.h"

#include <vector>

#include "Component.h"

namespace Gly
{
    class GLY_API Model : public Component
    {
    private:
        unsigned int vertexDataCount = 3;
        Material& material;
        std::vector<float> vertices;
        std::vector<unsigned int> triangles;
        unsigned int buffer;
        unsigned int indexBuffer;

    public:
        Model(const std::vector<float>& vertices, const std::vector<unsigned int>& triangles, Material& mat) :
            material(mat),
            vertices(vertices),
            triangles(triangles)
        {
        }

        void generateBuffer();
        void render();
    };
}

#pragma once
#include "framework.h"
#include "Color.h"

namespace Gly
{
    class Shader;

    class GLY_API Material
    {
    private:
        Shader* shader;
        Color color;
        int colorLocation;

    public:
        Material(Shader* shader);
        Material(Shader* shader, Color color);

        void useMaterial();
    };
}

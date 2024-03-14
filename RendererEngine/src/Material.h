#pragma once
#include "Color.h"

namespace Gly
{
    class Shader;

    class Material
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

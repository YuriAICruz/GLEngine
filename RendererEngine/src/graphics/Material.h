#pragma once
#include "Texture.h"
#include "../framework.h"
#include "../Color.h"

namespace Gly
{
    class Shader;

    class GLY_API Material
    {
    private:
        Shader* shader;
        Color color;
        int colorLocation;
        int mainTextureLocation;

    public:
        Material(Shader* shader);
        Material(Shader* shader, Color color);

        void useMaterial() const;

        bool getUniformLocation(int& location, const char* name);
        void setTexture(const Texture& tex);
    };
}

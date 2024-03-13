#pragma once

namespace Gly
{
    class Shader;

    class Material
    {
    private:
        Shader* shader;
    public:
        Material(Shader* shader) : shader(shader) {  }
    };
}

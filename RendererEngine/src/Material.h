#pragma once
#include "Shader.h"

namespace Gly
{
    class Shader;

    class Material
    {
    private:
        Shader* shader;
    public:
        Material(Shader* shader) : shader(shader) {  }
        unsigned int GetProgramId()
        {
            return shader->GetProgram();
        }
    };
}

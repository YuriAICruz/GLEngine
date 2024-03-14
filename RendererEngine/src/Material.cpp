#include "Material.h"

#include <iostream>
#include <ostream>
#include <GL/glew.h>

#include "Shader.h"
#include "Color.h"
#include "GLTools.h"

namespace Gly
{
    Material::Material(Shader* shader) : Material(shader, Color(1, 1, 1, 1))
    {
    }

    Material::Material(Shader* shader, Color color) : shader(shader), color(color)
    {
        auto u_color = "u_Color";

        GLCall(colorLocation = glGetUniformLocation(shader->GetProgram(), u_color));

        if (colorLocation == -1)
        {
            std::cerr << "could not find uniform location [" << u_color << "]" << std::endl;
            return;
        }
    }

    void Material::useMaterial()
    {
        GLCall(glUseProgram(shader->GetProgram()));
        GLCall(glUniform4f(colorLocation, color.r, color.g, color.b, color.a));
    }
}

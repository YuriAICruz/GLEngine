#include "Material.h"

#include <iostream>
#include <ostream>
#include <GL/glew.h>

#include "Shader.h"
#include "GLTools.h"
#include "../Color.h"

namespace Gly
{
    Material::Material(Shader* shader) : Material(shader, Color(1, 1, 1, 1))
    {
    }

    Material::Material(Shader* shader, Color color) : shader(shader), color(color)
    {
        getUniformLocation(colorLocation, "u_Color");
        getUniformLocation(mainTextureLocation, "u_MainTex");
    }

    void Material::useMaterial() const
    {
        GLCall(glUseProgram(shader->GetProgram()));
        GLCall(glUniform4f(colorLocation, color.r, color.g, color.b, color.a));
    }

    bool Material::getUniformLocation(int& location, const char* name)
    {
        GLCall(location = glGetUniformLocation(shader->GetProgram(), name));

        if (location == -1)
        {
            std::cerr << "could not find uniform location [" << name << "]" << std::endl;
            return false;
        }

        return true;
    }

    void Material::setTexture(const Texture& tex)
    {
        
    }
}

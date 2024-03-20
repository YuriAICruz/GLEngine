#include "Texture.h"

#include <fstream>

#include "GLTools.h"
#include "stb_image/stb_image.h"

namespace Gly
{
    Texture::Texture(const char* filePath)
    {
        stbi_set_flip_vertically_on_load(1);

        localBuffer = stbi_load(filePath, &width, &height, &channels, 4);

        GLCall(glGenTextures(1, &rendererId));
        GLCall(glBindTexture(GL_TEXTURE_2D, rendererId));

        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
        GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));

        if(localBuffer)
        {
            stbi_image_free(localBuffer);
        }
    }

    Texture::~Texture()
    {
        GLCall(glDeleteTextures(1, &rendererId));
    }

    void Texture::bind(unsigned int slot) const
    {
        GLCall(glActiveTexture(GL_TEXTURE0 + slot));
        GLCall(glBindTexture(GL_TEXTURE_2D, rendererId));
    }

    void Texture::unbind() const
    {
        GLCall(glBindTexture(GL_TEXTURE_2D, 0));
    }
}

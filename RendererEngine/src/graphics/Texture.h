#pragma once
#include "../framework.h"

namespace Gly
{
    class GLY_API Texture
    {
    private:
        unsigned int rendererId;
        unsigned char* localBuffer;
        int width;
        int height;
        int channels;
    public:
        Texture(const char* filePath);
        ~Texture();

        void bind(unsigned int slot = 0) const;
        void unbind() const;
    };
}

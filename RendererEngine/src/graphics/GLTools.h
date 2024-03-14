#pragma once
#include <iostream>
#include <GL/glew.h>

namespace Gly
{
#define GLCall(func) ErrorHandler::GLClearErrors();\
    func;\
    ErrorHandler::GLGetErrors(#func, __FILE__, __LINE__)

    class ErrorHandler
    {
    public:
        static void GLClearErrors()
        {
            while (glGetError() != GL_NO_ERROR);
        }

        static bool GLGetErrors(const char* function, const char* file, int line)
        {
            while (GLenum error = glGetError())
            {
                std::cerr << "[Open GL error] : (" << error << "): " << gluErrorString(error) << " [" << function << "] [" << file << ":" << line << "]\n";
                return false;
            }

            return true;
        }
    };
}

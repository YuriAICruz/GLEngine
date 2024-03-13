#pragma once
#include "framework.h"
#include <string>

class GLFWwindow;

namespace Gly
{
    class GlyRenderer;

    class GLY_API GlyWindow
    {
    private:
        GLFWwindow* window;
        GlyRenderer& renderer;

    public:
        GlyWindow(GlyRenderer& rdr, int width, int height, const std::string& title);
        ~GlyWindow();

        GLFWwindow* getGLFWindow() const
        {
            return window;
        }
    };
}

#pragma once
#include <string>

class GLFWwindow;

namespace Gly
{
    class GlyWindow
    {
    private:
        GLFWwindow* window;

    public:
        GlyWindow(){}
        GlyWindow(int width, int height, const std::string& title);
        ~GlyWindow();

        GLFWwindow* getGLFWindow() const
        {
            return window;
        }
    };
}

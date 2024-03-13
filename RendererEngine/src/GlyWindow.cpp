#include "GlyWindow.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>

namespace Gly
{
    GlyWindow::GlyWindow(int width, int height, const std::string& title)
    {
        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

        if (!window)
        {
            throw std::runtime_error("Failed to create GL window");
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);
    }

    GlyWindow::~GlyWindow()
    {
    }
}

#include "GlyWindow.h"
#include "GlyRenderer.h"

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Gly
{
    GlyWindow::GlyWindow(GlyRenderer& rdr, int width, int height, const std::string& title) : renderer(rdr)
    {
        window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create GL window");
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        auto err = glewInit();
        if (GLEW_OK != err)
        {
            std::stringstream ss;
            ss << "glewInit failed Error: ";
            ss << glewGetErrorString(err);
            throw std::runtime_error(ss.str());
        }

        std::cout << glGetString(GL_VERSION) << std::endl;
    }

    GlyWindow::~GlyWindow()
    {
        glfwTerminate();
    }

    bool GlyWindow::isOpen()
    {
        return !glfwWindowShouldClose(window);
    }

    void GlyWindow::render()
    {
        renderer.render(window);
    }
}

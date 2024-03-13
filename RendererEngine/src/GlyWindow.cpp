#include "GlyWindow.h"
#include "GlyRenderer.h"
#include "Model.h"

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GLTools.h"
#include "Shader.h"

namespace Gly
{
    GlyWindow::GlyWindow(GlyRenderer& rdr, int width, int height, const std::string& title) : renderer(rdr)
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to Initialize GL");
        }

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

        float vertices[] = {
            0.5, 0.5, 0,
            0.5, -0.5, 0,
            -0.5, -0.5, 0,
            -0.5, 0.5, 0
        };

        unsigned int triangles[] = {
            0, 1, 2,
            0, 2, 3
        };

        Shader shader = Shader("./shaders/unlit.vert.glsl", ".\\shaders\\unlit.frag.glsl");
        Material mat = Material(&shader);
        Model triangle = Model(
            std::vector<float>(std::begin(vertices), std::end(vertices)),
            std::vector<unsigned int>(std::begin(triangles), std::end(triangles)),
            Vector3(0, 0, 0),
            Vector3(1, 1, 1),
            mat
        );

        renderer.addToContext(&triangle);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            renderer.render(window);
        }
    }

    GlyWindow::~GlyWindow()
    {
        glfwTerminate();
    }
}

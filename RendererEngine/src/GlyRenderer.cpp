﻿#include "GlyRenderer.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Gly
{
    GlyRenderer::GlyRenderer(int argc, char* argv[])
    {
        // Loop through each argument from console
        // for (int i = 0; i < argc; ++i) {
        //     char* arg = argv[i];
        // }

        if (!glfwInit())
        {
            throw std::runtime_error("Failed to Initialize GL");
        }

        window = GlyWindow(640, 480, "Engine");

        auto err = glewInit();
        if (GLEW_OK != err)
        {
            std::stringstream ss;
            ss << "glewInit failed Error: ";
            ss << glewGetErrorString(err);
            throw std::runtime_error(ss.str());
        }

        std::cout << glGetString(GL_VERSION) << std::endl;

        float positions[6] = {
            1, 1,
            1, -1,
            -1, -1
        };

        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window.getGLFWindow()))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            /* Swap front and back buffers */
            glfwSwapBuffers(window.getGLFWindow());

            /* Poll for and process events */
            glfwPollEvents();
        }
    }

    GlyRenderer::~GlyRenderer()
    {
        glfwTerminate();
    }
}

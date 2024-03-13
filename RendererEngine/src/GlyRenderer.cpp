#include "GlyRenderer.h"

#include <exception>
#include <GLFW/glfw3.h>

namespace Gly
{
    GlyRenderer::GlyRenderer()
    {        
        GLFWwindow* window;

        if (!glfwInit())
        {
            throw std::exception("Failed to Initialize GL");
        }

        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            throw std::exception("Failed to create GL window");
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }

    GlyRenderer::~GlyRenderer()
    {
        glfwTerminate();
    }
}

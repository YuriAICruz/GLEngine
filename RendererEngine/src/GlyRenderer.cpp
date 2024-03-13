#include "GlyRenderer.h"
#include <stdexcept>
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

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window.getGLFWindow()))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

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

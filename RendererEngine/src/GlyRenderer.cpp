#include "GlyRenderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Gly
{
    GlyRenderer::GlyRenderer()
    {
    }

    GlyRenderer::~GlyRenderer()
    {
    }

    void GlyRenderer::render(GLFWwindow* window)
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    void GlyRenderer::addToContext(Model* model)
    {
        modelsToRender.push_back(model);

        model->generateBuffer();
    }

    void GlyRenderer::clearContext()
    {
        modelsToRender.clear();
    }

    void GlyRenderer::removeFromContext(Model* model)
    {
        auto it = std::find(modelsToRender.begin(), modelsToRender.end(), model);

        if (it != modelsToRender.end())
        {
            modelsToRender.erase(it);
        }
    }
}

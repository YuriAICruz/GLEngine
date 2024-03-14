#include "GlyRenderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GLTools.h"

namespace Gly
{
    GlyRenderer::GlyRenderer()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to Initialize GL");
        }
    }

    GlyRenderer::~GlyRenderer()
    {
    }

    void GlyRenderer::render(GLFWwindow* window)
    {
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        for (auto model : modelsToRender)
        {
            model->render();   
        }

        /* Swap front and back buffers */
        GLCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        GLCall(glfwPollEvents());
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

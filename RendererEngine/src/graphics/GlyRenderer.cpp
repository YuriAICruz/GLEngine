#include "GlyRenderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GLTools.h"
#include "Model.h"

namespace Gly
{
    GlyRenderer::GlyRenderer()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to Initialize GL");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
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

    void GlyRenderer::setCurrentCamera(Camera* camera)
    {
        currentCamera = camera;
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

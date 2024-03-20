#pragma once
#include "../framework.h"
#include <vector>

class GLFWwindow;

namespace Gly
{
    class Model;
    class Camera;

    class GLY_API GlyRenderer
    {
    private:
        std::vector<Model*> modelsToRender;
        Camera* currentCamera;

    public:
        GlyRenderer();
        ~GlyRenderer();

        void render(GLFWwindow* window);

        void addToContext(Model* model);
        void setCurrentCamera(Camera* camera);
        void clearContext();
        void removeFromContext(Model* model);
    };
}

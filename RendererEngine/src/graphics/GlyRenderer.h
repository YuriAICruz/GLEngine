#pragma once
#include "../framework.h"
#include "Model.h"

#include <vector>

class GLFWwindow;

namespace Gly
{
    class GLY_API GlyRenderer
    {
    private:
        std::vector<Model*> modelsToRender;
    public:
        GlyRenderer();
        ~GlyRenderer();

        void render(GLFWwindow* window);

        void addToContext(Model* model);
        void clearContext();
        void removeFromContext(Model* model);
    };
}

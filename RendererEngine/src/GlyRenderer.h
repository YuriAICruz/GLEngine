#pragma once
#include "framework.h"
#include "GlyWindow.h"

namespace Gly
{
    class GLY_API GlyRenderer
    {
    public:
        GlyRenderer();
        ~GlyRenderer();

    private:
        GlyWindow window;
    };
}

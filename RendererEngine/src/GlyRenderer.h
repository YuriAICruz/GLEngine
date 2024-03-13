﻿#pragma once
#include "framework.h"
#include "GlyWindow.h"

namespace Gly
{
    class GLY_API GlyRenderer
    {
    public:
        GlyRenderer(int argc, char* argv[]);
        ~GlyRenderer();

    private:
        GlyWindow window;
    };
}

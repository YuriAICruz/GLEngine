#include "GlyRenderer.h"
#include "GlyWindow.h"

int main(int argc, char* argv[])
{
    Gly::GlyRenderer renderer = Gly::GlyRenderer();
    Gly::GlyWindow window = Gly::GlyWindow(renderer, 640, 480, "Engine");
    return 0;
}

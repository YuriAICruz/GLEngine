#include <iostream>

#include "GlyRenderer.h"
#include "GlyWindow.h"
#include <windows.h>


int main(int argc, char* argv[])
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::cout << "Current directory path: " << buffer << std::endl;
    
    Gly::GlyRenderer renderer = Gly::GlyRenderer();
    Gly::GlyWindow window = Gly::GlyWindow(renderer, 640, 480, "Engine");
    return 0;
}

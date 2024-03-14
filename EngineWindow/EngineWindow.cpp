#include <iostream>

#include "GlyRenderer.h"
#include "GlyWindow.h"
#include "Model.h"
#include "Shader.h"
#include <windows.h>


int main(int argc, char* argv[])
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::cout << "Current directory path: " << buffer << std::endl;
    
    Gly::GlyRenderer renderer = Gly::GlyRenderer();
    
    Gly::GlyWindow window = Gly::GlyWindow(renderer, 640, 480, "Engine");
        
    float vertices[] = {
        0.5, 0.5, 0,
        0.5, -0.5, 0,
        -0.5, -0.5, 0,
        -0.5, 0.5, 0
    };

    unsigned int triangles[] = {
        0, 1, 2,
        0, 2, 3
    };

    Gly::Shader shader = Gly::Shader("./shaders/unlit.vert.glsl", ".\\shaders\\unlit.frag.glsl");
    Gly::Material mat = Gly::Material(&shader, Gly::Color(0.2f, 0.3f, 0.8f, 1.0f));
    Gly::Model triangle = Gly::Model(
        std::vector<float>(std::begin(vertices), std::end(vertices)),
        std::vector<unsigned int>(std::begin(triangles), std::end(triangles)),
        Gly::Vector3(0, 0, 0),
        Gly::Vector3(1, 1, 1),
        mat
    );

    renderer.addToContext(&triangle);
    
    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        window.render();
    }
    
    return 0;
}

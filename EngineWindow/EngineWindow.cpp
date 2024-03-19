#include <iostream>

#include "graphics/GlyRenderer.h"
#include "graphics/GlyWindow.h"
#include "Model.h"
#include "graphics/Shader.h"
#include <windows.h>

#include "Entity.h"

Gly::Entity CreateObject(Gly::Material* mat, float offset)
{
    float vertices[] = {
        0.5f + offset, 0.5f + offset, 0,
        0.5f + offset, -0.5f + offset, 0,
        -0.5f + offset, -0.5f + offset, 0,
        -0.5f + offset, 0.5f + offset, 0
    };

    unsigned int triangles[] = {
        0, 1, 2,
        0, 2, 3
    };

    Gly::Entity triangle = Gly::Entity();
    triangle.addComponent(std::make_shared<Gly::Model>(
        std::vector<float>(std::begin(vertices), std::end(vertices)),
        std::vector<unsigned int>(std::begin(triangles), std::end(triangles)),
        mat));
    return triangle;
}

int main(int argc, char* argv[])
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::cout << "Current directory path: " << buffer << std::endl;

    Gly::GlyRenderer renderer = Gly::GlyRenderer();

    Gly::GlyWindow window = Gly::GlyWindow(renderer, 640, 480, "Engine");

    Gly::Shader shader = Gly::Shader("./shaders/unlit.vert.glsl", ".\\shaders\\unlit.frag.glsl");
    Gly::Material mat = Gly::Material(&shader, Gly::Color(0.2f, 0.3f, 0.8f, 1.0f));
    Gly::Material matB = Gly::Material(&shader, Gly::Color(0.1f, 0.15f, 0.6f, 1.0f));

    auto triangle = CreateObject(&mat, 0);
    auto triangleB = CreateObject(&matB, 0.25f);
    auto triangleC = CreateObject(&matB, -0.25f);

    renderer.addToContext(triangleB.getComponent<Gly::Model>());
    renderer.addToContext(triangleC.getComponent<Gly::Model>());
    renderer.addToContext(triangle.getComponent<Gly::Model>());

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        window.render();
    }

    return 0;
}

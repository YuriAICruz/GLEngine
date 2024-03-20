#include <iostream>

#include "graphics/GlyRenderer.h"
#include "graphics/GlyWindow.h"
#include "graphics/Material.h"
#include "graphics/Model.h"
#include "ecs/Entity.h"
#include "graphics/Shader.h"
#include <windows.h>

#include "Color.h"
#include "ecs/Camera.h"
#include "graphics/Texture.h"


int main(int argc, char* argv[])
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    std::cout << "Current directory path: " << buffer << std::endl;

    Gly::GlyRenderer renderer = Gly::GlyRenderer();

    Gly::GlyWindow window = Gly::GlyWindow(renderer, 640, 480, "Engine");

    Gly::Shader shader = Gly::Shader("./shaders/unlit.vert.glsl", ".\\shaders\\unlit.frag.glsl");

    Gly::Texture tex("res/textures/face.jpg");

    Gly::Material mat = Gly::Material(&shader, Gly::Color(0.2f, 0.3f, 0.8f, 1.0f));
    Gly::Material matB = Gly::Material(&shader, Gly::Color(0.1f, 0.15f, 0.6f, 1.0f));

    mat.setTexture(tex);

    Gly::Entity plane = Gly::Entity();
    plane.addComponent(std::make_shared<Gly::Model>("res/models/plane.glb", &mat));
    Gly::Entity cross = Gly::Entity();
    cross.addComponent(std::make_shared<Gly::Model>("res/models/cross.gltf", &matB, false));

    Gly::Entity camera = Gly::Entity();
    camera.addComponent(std::make_shared<Gly::Camera>());

    renderer.addToContext(plane.getComponent<Gly::Model>());
    renderer.addToContext(cross.getComponent<Gly::Model>());
    renderer.setCurrentCamera(camera.getComponent<Gly::Camera>());

    /* Loop until the user closes the window */
    while (window.isOpen())
    {
        window.render();
    }

    return 0;
}

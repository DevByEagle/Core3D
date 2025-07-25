#include <iostream>
#include <Core3D/Core3D.h>

int main() {
    Core3D::GraphicsContext graphicsContext;

    if (Core3D::IsBackendSupported(graphicsContext.GetCurrentBackend())) {
        std::cout << "OpenGL backend is supported." << std::endl;
    } else {
        std::cout << "OpenGL backend is not supported." << std::endl;
    }

    graphicsContext.Present();

    return 0;
}
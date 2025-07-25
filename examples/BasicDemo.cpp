#include <Core3D/Core3D.h>
#include <iostream>

using Core3D::GraphicsBackend;

int main() {
    std::cout << "Is OpenGL Supported? "
              << (Core3D::IsBackendSupported(GraphicsBackend::OpenGL) ? "Yes" : "No")
              << std::endl;
    return 0;
}
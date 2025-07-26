#include <iostream>
#include <Core3D/Core3D.h>

int main() {
    Core3D::GraphicsContext graphicsContext;

    std::cout << graphicsContext.GetCurrentBackend();

    return 0;
}
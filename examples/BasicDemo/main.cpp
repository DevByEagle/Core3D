#include <iostream>
#include <Core3D/Core3D.h>

int main() {
    Core3D::GraphicsContext graphicsContext;

    graphicsContext.SetTitle("Core3D Basic Demo");

    graphicsContext.Present();

    return 0;
}
#include <iostream>
#include <Core3D/Core3D.h>

int main() {
    Core3D::GraphicsContext graphicsContext;

    while (!graphicsContext.IsRunning())
    {
        graphicsContext.Present();
    }
    
    return 0;
}
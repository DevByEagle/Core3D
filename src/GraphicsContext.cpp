#include "Core3D/Core3D.h"
#include "Core3D/GraphicsContext.h"

// Include the appropriate backend header based on the selected graphics backend
#if CORE3D_USE_OPENGL
    #include "Backends/OpenGL/GLBackend.h"
#endif

namespace Core3D
{
    GraphicsContext::GraphicsContext()
    {
        
    }
}
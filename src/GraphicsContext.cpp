#include "Core3D/Core3D.h"
#include "Core3D/GraphicsContext.h"

// Include the appropriate backend header based on the selected graphics backend
#if CORE3D_USE_OPENGL
    #include "Backends/OpenGL/GLBackend.h"
#endif

using namespace Core3D;

GraphicsContext::GraphicsContext() 
{
#if CORE3D_USE_OPENGL
    m_CurrentBackend = "OpenGL";
    GLBackend::Initialize();
#endif
}
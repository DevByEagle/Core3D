#include "Core3D/Core3D.h"
#include "Core3D/GraphicsContext.h"

// Include the appropriate backend header based on the selected graphics backend
#if CORE3D_BACKEND_OPENGL
    #include "Backends/OpenGL/GLBackend.h"
#endif

using namespace Core3D;

GraphicsContext::GraphicsContext() 
{
#if CORE3D_BACKEND_OPENGL
    m_CurrentBackend = "OpenGL";
    GLBackend::Initialize();
#endif
}

GraphicsContext::~GraphicsContext()
{
#if CORE3D_BACKEND_OPENGL
    GLBackend::Shutdown();
#endif
}

void GraphicsContext::Draw()
{
    return;
}

int GraphicsContext::GetWidth() const 
{
    return 0;
}

int GraphicsContext::GetHeight() const
{
    return 0;
}

void GraphicsContext::Present()
{
#if CORE3D_BACKEND_OPENGL
#endif
}
#include "Core3D/Core3D.h"
#include "Core3D/GraphicsContext.h"

#include "Backends/OpenGL/GLBackend.h"

namespace Core3D
{
    GraphicsContext::GraphicsContext(GraphicsBackend backend) : m_CurrentBackend(backend)
    {
    }

    GraphicsContext::~GraphicsContext()
    {
    };

    void GraphicsContext::Present()
    {
    }

    GraphicsBackend GraphicsContext::GetCurrentBackend() const 
    { 
        return m_CurrentBackend; 
    }

    bool IsBackendSupported(GraphicsBackend backend)
    {
        switch (backend)
        {
            case GraphicsBackend::DirectX:
                // Check for DirectX support (platform-specific)
                return false; // Placeholder, implement actual check
            case GraphicsBackend::OpenGL:
                return true;
            case GraphicsBackend::Metal:
                // Check for Metal support (macOS/iOS)
                return false; // Placeholder, implement actual check
            default:
                return false; // Unsupported backend
        }
    }
}
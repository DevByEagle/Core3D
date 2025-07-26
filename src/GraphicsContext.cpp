#include "Core3D/Core3D.h"
#include "Core3D/GraphicsContext.h"

// Include the appropriate backend header based on the selected graphics backend
#include "Backends/OpenGL/GLBackend.h"

namespace Core3D
{
    GraphicsContext::GraphicsContext(GraphicsBackend backend) : m_CurrentBackend(backend)
    {
        switch (backend)
        {
        case GraphicsBackend::OpenGL:
            GLBackend::Initialize();
            break;
        default:
            return; // Unsupported backend
        }
    }

    GraphicsContext::~GraphicsContext()
    {
        if (m_CurrentBackend == GraphicsBackend::OpenGL)
            GLBackend::Shutdown();
    }

    GraphicsBackend GraphicsContext::GetCurrentBackend() const
    {
        return m_CurrentBackend;
    }

    void GraphicsContext::SetTitle(const std::string& title)
    {
        switch (m_CurrentBackend)
        {
        case GraphicsBackend::OpenGL:
            GLBackend::SetWindowTitle(title);
            break;
        default:
            return; // Unsupported backend
        }
    }

    void GraphicsContext::SetSize(int width, int height)
    {
        switch (m_CurrentBackend)
        {
        case GraphicsBackend::OpenGL:
            GLBackend::SetWindowSize(width, height);
            break;
        default:
            return; // Unsupported backend
        }
    }

    void GraphicsContext::Present()
    {
        switch (m_CurrentBackend)
        {
        case GraphicsBackend::OpenGL:
            GLBackend::Present();
            break;
        default:
            return; // Unsupported backend
        }
    }
}
#pragma once

#include "Common.h"

namespace Core3D
{
    class GraphicsContext 
    {
    public:
        GraphicsContext(GraphicsBackend backend = GraphicsBackend::OpenGL);
        ~GraphicsContext();

        void Present();
        inline GraphicsBackend GetCurrentBackend() const;
    private:
        GraphicsBackend m_CurrentBackend;
    };
}
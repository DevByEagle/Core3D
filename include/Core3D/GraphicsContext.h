#pragma once

#include <string>
#include "Common.h"

namespace Core3D
{
    class GraphicsContext 
    {
    public:
        GraphicsContext(GraphicsBackend backend = GraphicsBackend::OpenGL);
        ~GraphicsContext();

        GraphicsBackend GetCurrentBackend() const;
    public:
        void SetTitle(const std::string& title);
        void SetSize(int width, int height);
        void Present();
    private:
        GraphicsBackend m_CurrentBackend;
    };
}
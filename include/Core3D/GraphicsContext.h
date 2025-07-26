#pragma once

#include <string>
#include "Common.h"

namespace Core3D
{
    class GraphicsContext 
    {
    public:
        GraphicsContext();
        ~GraphicsContext();

        bool IsRunning();
        void Draw();
        int GetWidth() const;
        int GetHeight() const;
        void Present();

        /// @return The name of the current graphics API in use.
        std::string GetCurrentBackend() const;
    private:
        GraphicsContext(const GraphicsContext&) = delete;
        GraphicsContext& operator=(const GraphicsContext&) = delete;

        std::string m_CurrentBackend;
    };
}
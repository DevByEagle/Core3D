#pragma once

namespace Core3D
{
    class GLBackend
    {
    public:
        static void Initialize();
        static void Shutdown();

        static void SetWindowTitle(const std::string& title);
        static void SetWindowSize(int width, int height);
        static bool ShouldWindowClose();
        static void Present();
    };
}
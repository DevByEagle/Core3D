#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GLBackend.h"

namespace Core3D
{
    static GLFWwindow* window = nullptr;

    void GLBackend::Initialize()
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }
    }

    void GLBackend::Shutdown()
    {

    }

    void GLBackend::SetWindowTitle(const std::string& title)
    {

    }

    void GLBackend::SetWindowSize(int width, int height)
    {
    }

    void GLBackend::Present()
    {
        
    }
}
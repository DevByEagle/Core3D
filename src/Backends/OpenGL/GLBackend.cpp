#include <iostream>
#include "GLBackend.h"

#ifndef __APPLE__
#include <GL/glew.h>
#include <GLFW/glfw3.h>


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

        window = glfwCreateWindow(0, 0, "Core3D", nullptr, nullptr);
        if (!window)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);
        glewInit();
    }

    void GLBackend::Shutdown()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void GLBackend::SetWindowTitle(const std::string& title)
    {
        glfwSetWindowTitle(window, title.c_str());
    }

    void GLBackend::SetWindowSize(int width, int height)
    {
        if (window)
        {
            glfwSetWindowSize(window, width, height);
        }
        else
        {
            std::cerr << "Window not initialized" << std::endl;
            return;
        }
    }

    void GLBackend::Present()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
#endif
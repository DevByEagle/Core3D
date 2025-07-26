// GLBackend.cpp

#include <iostream>

#ifndef __APPLE__  // Only compile if not on Apple
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif

#include "GLBackend.h"

namespace Core3D {

#ifndef __APPLE__  // Entire implementation is skipped on Apple

    static GLFWwindow* window = nullptr;

    void GLBackend::Initialize() {
        if (!glfwInit()) {
            std::cerr << "[Core3D::GLBackend] Failed to initialize GLFW" << std::endl;
            return;
        }

        window = glfwCreateWindow(800, 600, "Core3D", nullptr, nullptr);
        if (!window) {
            std::cerr << "[Core3D::GLBackend] Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        GLenum glewStatus = glewInit();
        if (glewStatus != GLEW_OK) {
            std::cerr << "[Core3D::GLBackend] Failed to initialize GLEW: "
                      << glewGetErrorString(glewStatus) << std::endl;
            glfwDestroyWindow(window);
            glfwTerminate();
            return;
        }
    }

    void GLBackend::Shutdown() {
        if (window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
        glfwTerminate();
    }

    void GLBackend::SetWindowTitle(const std::string& title) {
        if (window) {
            glfwSetWindowTitle(window, title.c_str());
        } else {
            std::cerr << "[Core3D::GLBackend] Cannot set title - window is null." << std::endl;
        }
    }

    void GLBackend::SetWindowSize(int width, int height) {
        if (window) {
            glfwSetWindowSize(window, width, height);
        } else {
            std::cerr << "[Core3D::GLBackend] Cannot resize - window is null." << std::endl;
        }
    }

    bool GLBackend::ShouldWindowClose()
    {
        return glfwWindowShouldClose(window);
    }

    void GLBackend::Present() {
        if (window) {
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

#endif  // !__APPLE__

} // namespace Core3D

if(CORE3D_USE_OPENGL)
    # Platform-specific OpenGL linking
    if (WIN32)
        add_subdirectory(thirdparty/glew)
        target_link_libraries(Core3D PRIVATE opengl32)
    elseif(APPLE)
        MESSAGE(FATAL_ERROR "OpenGL backend is not supported on macOS. Please use Metal instead.")
    elseif(UNIX)
        find_package(OpenGL REQUIRED)
        find_package(GLEW REQUIRED)

        target_link_libraries(Core3D PRIVATE OpenGL::GL GLEW::GLEW)
    endif()
endif()

# Glfw integration for window management with OpenGL
if(CORE3D_USE_OPENGL)
    # Platform-specific GLFW linking
    if(WIN32)
        add_subdirectory(thirdparty/glfw)
        target_link_libraries(Core3D PRIVATE glfw)
    elseif(APPLE)
        MESSAGE(FATAL_ERROR "OpenGL backend is not supported on macOS. Please use Metal instead.")
    elseif(UNIX)
        find_package(glfw3 REQUIRED)
        target_link_libraries(Core3D PRIVATE glfw)
    endif()
endif()
if(CORE3D_USE_OPENGL)
    # Platform-specific OpenGL linking
    if(WIN32)
        target_link_libraries(Core3D PRIVATE opengl32)
    elseif(APPLE)
        MESSAGE(FATAL_ERROR "OpenGL backend is not supported on macOS. Please use Metal instead.")
    elseif(UNIX)
        find_package(OpenGL REQUIRED)
        target_link_libraries(Core3D PRIVATE OpenGL::GL)
    endif()

    target_compile_definitions(Core3D PRIVATE CORE3D_BACKEND_OPENGL)
endif()

# Glfw integration for window management with OpenGL
if(CORE3D_USE_OPENGL)
    find_package(glfw3 REQUIRED)
    target_link_libraries(Core3D PRIVATE glfw)
endif()
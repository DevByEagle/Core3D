if(CORE3D_USE_OPENGL)
    if(APPLE)
        message(WARNING "OpenGL backend is not supported on macOS. Disabling OpenGL support.")

        list(REMOVE_ITEM CORE3D_SOURCES
            "${CMAKE_CURRENT_SOURCE_DIR}/Backends/OpenGL/GLBackend.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/Backends/OpenGL/GLBackend.h"
        )
    elseif(WIN32)
        # GLEW
        add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/glew ${CMAKE_BINARY_DIR}/thirdparty/glew)
        target_link_libraries(Core3D PRIVATE opengl32 GLEW)

        # GLFW
        add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/glfw ${CMAKE_BINARY_DIR}/thirdparty/glfw)
        target_link_libraries(Core3D PRIVATE glfw)
    elseif(UNIX AND NOT APPLE)
        # OpenGL
        find_package(OpenGL REQUIRED)
        target_link_libraries(Core3D PRIVATE OpenGL::GL)

        # GLEW
        add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/glew ${CMAKE_BINARY_DIR}/thirdparty/glew)
        target_link_libraries(Core3D PRIVATE GLEW)

        # GLFW
        find_package(glfw3 REQUIRED)
        target_link_libraries(Core3D PRIVATE glfw)
    endif()

    if (NOT APPLE)
        target_compile_definitions(Core3D PRIVATE CORE3D_BACKEND_OPENGL)
    endif()
endif()

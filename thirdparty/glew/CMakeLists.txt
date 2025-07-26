project(GLEW LANGUAGES C)

option(GLEW_BUILD_UTILS "Build glewinfo and visualinfo" ON)
option(GLEW_NO_GLU "Disable GLU support" ON)

include(GNUInstallDirs)

# Find OpenGL package
find_package(OpenGL REQUIRED)

if (UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
endif()

# Header files path
set(GLEW_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/GL
)

# Source files
set(GLEW_SRC ${PROJECT_SOURCE_DIR}/src/glew.c)

# Compile definitions
add_compile_definitions(GLEW_BUILD)
if (GLEW_NO_GLU)
    add_compile_definitions(GLEW_NO_GLU)
endif()

include_directories(${GLEW_INCLUDE_DIRS})

if (UNIX AND NOT APPLE)
    include_directories(${X11_INCLUDE_DIR})
endif()

if (BUILD_SHARED_LIBS)
    add_library(GLEW SHARED ${GLEW_SRC})
    set_target_properties(GLEW PROPERTIES OUTPUT_NAME GLEW)
    target_include_directories(GLEW PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    )
    target_link_libraries(GLEW PRIVATE ${CMAKE_DL_LIBS} OpenGL::GL)
    if (UNIX AND NOT APPLE)
        target_link_libraries(GLEW PRIVATE ${X11_LIBRARIES})
    endif()
else()
    add_library(GLEW_static STATIC ${GLEW_SRC})
    set_target_properties(GLEW_static PROPERTIES OUTPUT_NAME GLEW)
    target_include_directories(GLEW_static PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    )
    target_compile_definitions(GLEW_static PRIVATE GLEW_STATIC)
    target_link_libraries(GLEW_static PRIVATE OpenGL::GL)
    if (UNIX AND NOT APPLE)
        target_link_libraries(GLEW_static PRIVATE ${X11_LIBRARIES})
    endif()
endif()

# Utilities (glewinfo and visualinfo)
if (GLEW_BUILD_UTILS)
    add_executable(glewinfo src/glewinfo.c)
    add_executable(visualinfo src/visualinfo.c)

    target_link_libraries(glewinfo PRIVATE GLEW OpenGL::GL ${CMAKE_DL_LIBS})
    target_link_libraries(visualinfo PRIVATE GLEW OpenGL::GL ${CMAKE_DL_LIBS})

    target_include_directories(glewinfo PRIVATE ${GLEW_INCLUDE_DIRS})
    target_include_directories(visualinfo PRIVATE ${GLEW_INCLUDE_DIRS})

    if (UNIX AND NOT APPLE)
        target_link_libraries(glewinfo PRIVATE ${X11_LIBRARIES})
        target_link_libraries(visualinfo PRIVATE ${X11_LIBRARIES})
    endif()
endif()


install(DIRECTORY include/GL DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (BUILD_SHARED_LIBS)
    install(TARGETS GLEW EXPORT GLEWTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
else()
     install(TARGETS GLEW_static EXPORT GLEWTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
endif()

if (GLEW_BUILD_UTILS)
    install(TARGETS glewinfo visualinfo
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/glew.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/glew.pc
    @ONLY
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/glew.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

install(EXPORT GLEWTargets
    FILE GLEWTargets.cmake
    NAMESPACE GLEW::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/GLEW
)
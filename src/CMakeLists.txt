file(GLOB_RECURSE CORE3D_SOURCES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE CORE3D_HEADERS CONFIGURE_DEPENDS ../include/Core3D/*.h)

# if (APPLE AND CORE3D_USE_OPENGL)
#     list(REMOVE_ITEM CORE3D_SOURCES
#         "${CMAKE_CURRENT_SOURCE_DIR}/Backends/OpenGL/GLBackend.cpp"
#     )
# endif()

add_library(Core3D ${CORE3D_SOURCES} ${CORE3D_HEADERS})
include(LibraryConfigurations)
target_include_directories(Core3D
                          PUBLIC
                          $<INSTALL_INTERFACE:include>
                          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
                          PRIVATE
                          ${CMAKE_SOURCE_DIR}/thirdparty/glew/include
)

# Defines the installation rules for this library when 'cmake --install' is executed.
# Controls where headers, binaries, and other targets are placed on the system.
include(InstallConfigurations)
file(GLOB_RECURSE CORE3D_SOURCES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE CORE3D_HEADERS CONFIGURE_DEPENDS ../include/Core3D/*.h)

add_library(Core3D ${CORE3D_SOURCES} ${CORE3D_HEADERS})
target_include_directories(Core3D
                          PUBLIC
                          $<INSTALL_INTERFACE:include>
                          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)

# Backends
if (CORE3D_USE_OPENGL)
    target_compile_definitions(Core3D PRIVATE CORE3D_BACKEND_OPENGL)
endif()

# Defines the installation rules for this library when 'cmake --install' is executed.
# Controls where headers, binaries, and other targets are placed on the system.
include(InstallConfigurations)
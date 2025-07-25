file(GLOB_RECURSE CORE3D_SOURCES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE CORE3D_HEADERS CONFIGURE_DEPENDS ../include/Core3D/*.h)

add_library(Core3D ${CORE3D_SOURCES} ${CORE3D_HEADERS})
target_include_directories(Core3D PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

if(CORE3D_USE_OPENGL)
    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED)
    
    target_compile_definitions(Core3D PRIVATE CORE3D_USE_OPENGL)
    target_link_libraries(Core3D PRIVATE OpenGL::GL glfw)
endif()
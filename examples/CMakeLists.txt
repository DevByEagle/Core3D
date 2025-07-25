project(examples)

set(EXAMPLES
    BasicDemo
)

find_package(Core3D REQUIRED)

foreach(EXAMPLE ${EXAMPLES})
    add_executable(${EXAMPLE} ${EXAMPLE}/main.cpp)
    
    target_link_libraries(${EXAMPLE} Core3D)
endforeach()

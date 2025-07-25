include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Define a global install destination root
set(CORE3D_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/Core3D")

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/Core3D"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h"
)

install(
    TARGETS Core3D EXPORT Core3DTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}       # .exe, .dll
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}       # .so, .dylib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}       # .lib, .a
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(EXPORT Core3DTargets
    FILE Core3DTargets.cmake
    NAMESPACE Core3D::
    DESTINATION ${CORE3D_INSTALL_CMAKEDIR}
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/Core3DConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/Core3D.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Core3DConfig.cmake"
    INSTALL_DESTINATION ${CORE3D_INSTALL_CMAKEDIR}
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/Core3DConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/Core3DConfigVersion.cmake"
    DESTINATION ${CORE3D_INSTALL_CMAKEDIR}
)

install(FILES
    "${PROJECT_SOURCE_DIR}/LICENSE"
    "${PROJECT_SOURCE_DIR}/README.md"
    DESTINATION ${CMAKE_INSTALL_DATADIR}/Core3D
)
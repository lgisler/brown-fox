cmake_minimum_required(VERSION 3.15...3.18)

project(BrownFox
    VERSION 0.1.0
    LANGUAGES CXX
)

add_subdirectory(src)

add_subdirectory(app)

if(TEST_BROWNFOX OR (CMAKE_SOURCE_DIR STREQUAL BrownFox_SOURCE_DIR))
    include(CTest)
    add_subdirectory(tests)
endif()

include(GNUInstallDirs)

install(EXPORT BrownFox_Apps
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/BrownFox
    NAMESPACE BrownFox::
    FILE BrownFox_Apps.cmake
    COMPONENT BrownFox_Apps
)

install(EXPORT BrownFox_Libs
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/BrownFox
    NAMESPACE BrownFox::
    FILE BrownFox_Libs.cmake
    COMPONENT BrownFox_Libs
)

configure_file(
    ${BrownFox_SOURCE_DIR}/cmake/BrownFoxConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/BrownFoxConfig.cmake
    @ONLY
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/BrownFoxConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/BrownFox
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # include(CPack) will happen inside the following call
    add_subdirectory(packaging)
endif()

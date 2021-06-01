add_library(BrownFox_Body)
add_library(BrownFox::Body ALIAS BrownFox_Body)

target_sources(BrownFox_Body
    PRIVATE
        legs.cc
        ears.cc
        eyes.cc
        fox.cc
)

target_include_directories(BrownFox_Body
    PUBLIC
        $<BUILD_INTERFACE:${BrownFox_SOURCE_DIR}/include>
)

set_target_properties(BrownFox_Body PROPERTIES
    OUTPUT_NAME Body
    EXPORT_NAME Body
)

target_compile_features(BrownFox_Body
    PUBLIC
        cxx_std_17
)

set_target_properties(BrownFox_Body
    PROPERTIES
        SOVERSION   ${PROJECT_VERSION_MAJOR}
        VERSION     ${PROJECT_VERSION}
)

include(GNUInstallDirs)

install(DIRECTORY ${BrownFox_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN *.h
)

install(TARGETS BrownFox_Body
    EXPORT BrownFox_Libs
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/BrownFox
    COMPONENT BrownFox_Libs
)

install(EXPORT BrownFox_Libs
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/BrownFox
    NAMESPACE BrownFox::
    FILE BrownFox_Libs.cmake
    COMPONENT BrownFox_Libs
)

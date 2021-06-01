add_executable(BrownFox_BrownFox)
add_executable(BrownFox::BrownFox ALIAS BrownFox_BrownFox)

target_sources(BrownFox_BrownFox
    PRIVATE
        main.cc
)

target_link_libraries(BrownFox_BrownFox
    PRIVATE
        BrownFox::Body
)

include(GNUInstallDirs)

file(RELATIVE_PATH relDir
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(BrownFox_BrownFox PROPERTIES
    OUTPUT_NAME BrownFox
    EXPORT_NAME BrownFox
    INSTALL_RPATH "$ORIGIN;$ORIGIN/${relDir}"
)

install(TARGETS BrownFox_BrownFox
    EXPORT BrownFox_Apps
    COMPONENT BrownFox_Apps
)

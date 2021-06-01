add_executable(BrownFox_BrownFox)
add_executable(BrownFox::BrownFox ALIAS BrownFox_BrownFox)

target_sources(BrownFox_BrownFox
    PRIVATE
        main.cc
)

target_include_directories(BrownFox_BrownFox
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(BrownFox_BrownFox
    PRIVATE
        BrownFox::Body
)

set_target_properties(BrownFox_BrownFox PROPERTIES
    OUTPUT_NAME BrownFox
    EXPORT_NAME BrownFox
)

include(GNUInstallDirs)
install(TARGETS BrownFox_BrownFox
    EXPORT BrownFox_Apps
    COMPONENT BrownFox_Apps
)

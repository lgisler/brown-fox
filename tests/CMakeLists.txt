cmake_minimum_required(VERSION 3.14...3.18)

include(FetchContent)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0 # Using a commit HASH is more efficient
)

FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest ALIAS gtest)
add_library(GTest::Main ALIAS gtest_main)
add_library(GMock::GMock ALIAS gmock)
add_library(GMock::Main ALIAS gmock_main)

add_executable(BrownFox_TestJump)
add_executable(BrownFox::TestJump ALIAS BrownFox_TestJump)

target_sources(BrownFox_TestJump
    PRIVATE
        test-jump.cc
)

target_include_directories(BrownFox_TestJump
    PRIVATE
        ${BrownFox_SOURCE_DIR}/app
)

target_link_libraries(BrownFox_TestJump
    PRIVATE
        BrownFox::Body
        GTest::Main
)

add_test(NAME Jump COMMAND BrownFox_TestJump)

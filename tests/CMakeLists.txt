include(FetchContent)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
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

target_link_libraries(BrownFox_TestJump
    PRIVATE
        BrownFox::Body
        GTest::Main
)

add_test(NAME Jump COMMAND BrownFox_TestJump)

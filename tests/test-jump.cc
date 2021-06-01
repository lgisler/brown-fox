#include <brown-fox/fox.h>

#include "gtest/gtest.h"

TEST(WhatDidTheFoxSay, Trivial) {
    BrownFox::Fox fox;
    EXPECT_EQ(fox.whatDidTheFoxSay(), "The quick brown fox jumped over the lazy dog.");
}

#pragma once

#include <iostream>

#include <brown-fox/ears.h>
#include <brown-fox/eyes.h>
#include <brown-fox/legs.h>

namespace BrownFox {
    class Fox {

        public:
            Fox() = default;

            std::string whatDidTheFoxSay();

        private:
            Ears _ears {};
            Eyes _eyes {};
            Legs _legs {};
    };
}

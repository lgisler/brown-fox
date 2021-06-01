#pragma once

#include <string>

#include <brown-fox/units.h>

namespace BrownFox {
    class Ears {

        public:
            enum class Size {
                Small,
                Medium,
                Large,
                Unknown
            };

            Ears() = default;
            bool setSizeOfEars(BrownFox::Ears::Size size);

        private:

            BrownFox::Units::Degrees _rotation_of_ear { 150.0 };
            BrownFox::Ears::Size _size { BrownFox::Ears::Size::Small };

            int _number { 2 };
    };
}

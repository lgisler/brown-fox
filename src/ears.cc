#include <brown-fox/ears.h>

namespace BrownFox {
    bool Ears::setSizeOfEars(Ears::Size size) {
        _size = size;

        if ( size == Ears::Size::Unknown )
            return false;

        return true;
    }
}

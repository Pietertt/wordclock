#include "include/precomp.h"

namespace Wordclock {

    Word::Word() {

    }

    int Word::getPosition() {
        return this->position;
    }

    void Word::setPosition(int position) {
        this->position = position;
    }

    int Word::getLength() {
        return this->length;
    }

    void Word::setLength(int length) {
        this->length = length;
    }

    volatile uint8_t* Word::getRegister() {
        return this->reg;
    }

    void Word::setRegister(volatile uint8_t* reg) {
        this->reg = reg;
    }
}

#include "include/precomp.h"

namespace Wordclock {

    Word::Word(Wordclock* wordclock, Register* reg, int place) {
        this->wordclock = wordclock;
        this->reg = reg;
        this->place = place;
    }

    void Word::on() {
        this->getRegister()->setData(true, this->getPlace());
    }

    void Word::off() {
        this->getRegister()->setData(false, this->getPlace());
    }

    void Word::toggle() {
        this->getRegister()->toggleData(this->getPlace());
    }

    void Word::test() {
        this->on();
        this->getRegister()->shiftOut();
        _delay_ms(25);
        this->off();
        this->getRegister()->shiftOut();
        _delay_ms(25);
    }

    Register* Word::getRegister() {
        return this->reg;
    }

    void Word::setRegister(Register* reg) {
        this->reg = reg;
    }

    int Word::getPlace() {
        return this->place;
    }

    void Word::setPlace(int place) {
        this->place = place;
    }

}

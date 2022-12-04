#include "../include/precomp.h"

namespace Wordclock {

    DoubleRegister::DoubleRegister(Register* dataRegister, Register* latchRegister, Register* clockRegister, int dataPin, int latchPin, int clockPin) {
        this->setDataRegister(dataRegister);
        this->setClockRegister(clockRegister);
        this->setLatchRegister(latchRegister);
        this->setClockPin(clockPin);
        this->setLatchPin(latchPin);
        this->setDataPin(dataPin);
        this->setData(0b00000000);
    }

    void DoubleRegister::setDataRegister(Register* reg) {
        this->dataRegister = reg;
    }

    Register* DoubleRegister::getDataRegister() {
        return this->dataRegister;
    }

    void DoubleRegister::setClockRegister(Register* reg) {
        this->clockRegister = reg;
    }

    Register* DoubleRegister::getClockRegister() {
        return this->clockRegister;
    }

    void DoubleRegister::setLatchRegister(Register* reg) {
        this->latchRegister = reg;
    }

    Register* DoubleRegister::getLatchRegister() {
        return this->latchRegister;
    }

    void DoubleRegister::shiftOut() {
        // if (this->getCopyData() == this->getData()) {
        //     // return; // misschien sws een return voor snelheids controle
        // }

        this->getLatchRegister()->setData(0, this->getLatchPin());
        this->getLatchRegister()->shiftOut();

        for (int i = 0; i < 8; i++) {
            this->getDataRegister()->setData(this->getData() & (1 << (7 - i)), this->getDataPin());
            this->getDataRegister()->shiftOut();
            
            this->getClockRegister()->setData(1, this->getClockPin());
            this->getClockRegister()->shiftOut();
            this->getClockRegister()->setData(0, this->getClockPin());
            this->getClockRegister()->shiftOut();
        }

        this->getLatchRegister()->setData(1, this->getLatchPin());
        this->getLatchRegister()->shiftOut();
    }
}

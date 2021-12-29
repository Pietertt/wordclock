#include "include/precomp.h"

void* operator new(size_t objsize) { 
    return malloc(objsize); 
} 

void operator delete(void* obj) { 
    free(obj); 
} 

namespace Wordclock {
    Wordclock::Wordclock() {
        this->time = new Time();
    }

    void Wordclock::setup() {
        DDRB |= 0B111111;
        DDRC |= 0B111111;
        DDRD |= 0B11111111;

        Word* UUR = new Word();
        UUR->setPosition(0);
        UUR->setLength(3);
        UUR->setRegister(&PORTB);

        this->words[0] = UUR;

        this->a = new Register(4, 3, 2, &PORTD);
        this->b = new Register(7, 6, 5, &PORTD);
        this->c = new Register(2, 1, 0, &PORTB);
        this->d = new Register(5, 4, 3, &PORTB);
        this->e = new Register(2, 1, 0, &PORTC);
        this->f = new Register(7, 6, 5, &PORTC);
        this->g = new Register(2, 3, 4, &PORTC);

        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->b, 0b00000000);

        while(true) {
            this->loop();
        }

    }

    void Wordclock::shiftOut(Register* reg, byte value) {
        *reg->getRegister() &= ~(0b1 << reg->getLatchPin());

        for (int i = 0; i < 8; i++)  {
            if (value & (1 << (7 - i))) {
                *reg->getRegister() |= (0b1 << reg->getDataPin());
            } else {
                *reg->getRegister() &= ~(0b1 << reg->getDataPin());
            }
            *reg->getRegister() |= (0b1 << reg->getClockPin());
            *reg->getRegister() &= ~(0b1 << reg->getClockPin());
        }

        *reg->getRegister() |= (0b1 << reg->getLatchPin());
    }

    void Wordclock::doubleShiftOut(Register *a, Register *b, byte value) {
        a->setData(0, b->getLatchPin());
        this->shiftOut(a, a->getData());

        for (int i = 0; i < 8; i++) {
            if (value & (1 << (7 - i))) {
                a->setData(1, b->getDataPin());
                this->shiftOut(a, a->getData());
            } else {
                a->setData(0, b->getDataPin());
                this->shiftOut(a, a->getData());
            }
            a->setData(1, b->getClockPin());
            this->shiftOut(a, a->getData());
            a->setData(0, b->getClockPin());
            this->shiftOut(a, a->getData());
        }

        a->setData(1, b->getLatchPin());
        this->shiftOut(a, a->getData());
    }

    void Wordclock::blink() {
        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->b, 0b00000000);
        this->shiftOut(this->c, 0b00000000);
        this->shiftOut(this->d, 0b00000000);
        this->doubleShiftOut(this->e, this->f, 0b00000000);
        this->doubleShiftOut(this->e, this->g, 0b00000000);
        _delay_ms(200);

        this->shiftOut(this->a, 0b11111111);
        this->shiftOut(this->b, 0b11111111);
        this->shiftOut(this->c, 0b11111111);
        this->shiftOut(this->d, 0b11111111);
        this->doubleShiftOut(this->e, this->f, 0b11111111);
        this->doubleShiftOut(this->e, this->g, 0b11111111);
        _delay_ms(200);
    }

    void Wordclock::loop() {
        for (int i = 0; i < sizeof(this->words) / sizeof(this->words[0]); i++) {
            // Word* word = this->words[i];
            // byte value = 0b00000000;
            // for (int j = word->getPosition(); j < word->getLength(); j++) {
            //     value |= (0b1 << j);
            // }
            // this->shiftOut(&PORTB, 0b11111111);
            this->shiftOut(this->a, 0b00000000);
        }
    }
}
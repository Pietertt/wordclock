#include "include/precomp.h"

void* operator new(size_t objsize) { 
    return malloc(objsize); 
} 

void operator delete(void* obj) { 
    free(obj); 
} 

namespace Wordclock {
    Wordclock::Wordclock() {

    }

    void Wordclock::setup() {
        DDRB |= 0B111111;
        DDRC |= 0B111111;
        DDRD |= 0B11111111;

        this->a = new Register(4, 3, 2, &PORTD);
        this->b = new Register(7, 6, 5, &PORTD);
        this->c = new Register(2, 1, 0, &PORTB);
        this->d = new Register(5, 4, 3, &PORTB);

        this->e = new Register(2, 1, 0, &PORTC);

        this->f = new Register(7, 6, 5, &PORTC);
        this->g = new Register(2, 3, 4, &PORTC);

        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->b, 0b00000000);
        this->shiftOut(this->c, 0b00000000);
        this->shiftOut(this->d, 0b00000000);

        this->doubleShiftOut(this->e, this->f, 0b00000000);
        this->doubleShiftOut(this->e, this->g, 0b00000000);
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
        _delay_ms(1000);

        this->shiftOut(this->a, 0b11111111);
        this->shiftOut(this->b, 0b11111111);
        this->shiftOut(this->c, 0b11111111);
        this->shiftOut(this->d, 0b11111111);
        this->doubleShiftOut(this->e, this->f, 0b11111111);
        this->doubleShiftOut(this->e, this->g, 0b11111111);
        _delay_ms(1000);
    }

    void Wordclock::loop() {
        this->a->loop();
        this->b->loop();
        this->c->loop();
        this->d->loop();
        this->e->doubleLoop(this->f);
        this->e->doubleLoop(this->g);
    }

    void Wordclock::clear_display() {
        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->b, 0b00000000);
        this->shiftOut(this->c, 0b00000000);
        this->shiftOut(this->d, 0b00000000);
        this->shiftOut(this->e, 0b00000000);
        this->shiftOut(this->f, 0b00000000);
        this->shiftOut(this->g, 0b00000000);
        this->doubleShiftOut(this->e, this->f, 0b00000000);
        this->doubleShiftOut(this->e, this->g, 0b00000000);
    }

    void Wordclock::decide_time(Time* time) {
        // this->clear_display();
        

        int minutes = time->getMinutes();
        int hour = time->getHour();

        switch (minutes) {
            case 2 ... 7:
                this->display_eerste_vijf();
                this->display_over();
                break;
            case 8 ... 12:
                this->display_eerste_tien();
                this->display_over();
                break;
            case 13 ... 22:
                this->display_eerste_tien();
                this->display_voor();
                this->display_half();
                break;
            case 23 ... 27:
                this->display_eerste_vijf();
                this->display_voor();
                break;
            case 28 ... 32:
                this->display_half();
                break;
            case 33 ... 37:
                this->display_eerste_vijf();
                this->display_over();
                break;
            case 38 ... 42:
                this->display_eerste_tien();
                this->display_over();
                this->display_half();
                break;
            case 43 ... 47:
                this->display_kwart();
                this->display_voor();
                break;
            case 48 ... 52:
                this->display_eerste_tien();
                this->display_voor();
                break;
            case 53 ... 57:
                this->display_eerste_vijf();
                this->display_voor();
                break;
        }

        switch(hour) {
            case 1:
            case 13:
                this->display_een();
                break;
            case 2:
            case 14:
                this->display_twee();
                break;
            case 4:
            case 16:
                this->display_vier();
                break;
            case 5:
            case 17:
                this->display_tweede_vijf();
                break;
            case 11:
            case 23:
                this->display_elf();
                break;
        }

        this->display_het();
        this->display_is();
    }

    void Wordclock::display_het() {
        this->shiftOut(this->d, 0b00000000);
        this->shiftOut(this->d, 0b11100000);
    }

    void Wordclock::display_is() {
        this->shiftOut(this->d, 0b00000000);
        this->shiftOut(this->d, 0b00011000);
    }

    void Wordclock::display_eerste_vijf() {
        this->shiftOut(this->c, 0b00000000);
        this->shiftOut(this->d, 0b00000000);
        this->shiftOut(this->c, 0b10000000);
        this->shiftOut(this->d, 0b00000111);
    }

    void Wordclock::display_eerste_tien() {
        this->shiftOut(this->c, 0b00000000);
        this->shiftOut(this->c, 0b01111000);
    }

    void Wordclock::display_kwart() {
        this->shiftOut(this->b, 0b00000000);
        this->shiftOut(this->c, 0b00000000);
        this->shiftOut(this->b, 0b11000000);
        this->shiftOut(this->c, 0b00000111);
    }

    void Wordclock::display_over() {
        this->shiftOut(this->b, 0b00000000);
        this->shiftOut(this->b, 0b00111100);
    }

    void Wordclock::display_voor() {
        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->b, 0b00000000);
        this->shiftOut(this->a, 0b11000000);
        this->shiftOut(this->b, 0b00000011);
    }

    void Wordclock::display_half() {
        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->a, 0b00111100);
    }

    void Wordclock::display_elf() {
        this->shiftOut(this->a, 0b00000000);
        this->shiftOut(this->a, 0b00000011);
        this->doubleShiftOut(this->e, this->f, 0b00000000);
        this->doubleShiftOut(this->e, this->f, 0b10000000);
    }

    void Wordclock::display_tweede_vijf() {
        this->doubleShiftOut(this->e, this->f, 0b00000000);
        this->doubleShiftOut(this->e, this->f, 0b01111000);
    }

    void Wordclock::display_twee() {
        this->doubleShiftOut(this->e, this->f, 0b00000000);
        this->doubleShiftOut(this->e, this->g, 0b00000000);
        this->doubleShiftOut(this->e, this->f, 0b00000111);
        this->doubleShiftOut(this->e, this->g, 0b10000000);
    }

    void Wordclock::display_een() {
        this->doubleShiftOut(this->e, this->g, 0b00000000);
        this->doubleShiftOut(this->e, this->g, 0b01110000);
    }

    void Wordclock::display_vier() {
        this->doubleShiftOut(this->e, this->g, 0b00000000);
        this->doubleShiftOut(this->e, this->g, 0b00001111);
    }
}

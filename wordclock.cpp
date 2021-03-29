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

        Register* a = new Register(4, 3, 2, &PORTD);
        Register* b = new Register(7, 6, 5, &PORTD);
        Register* c = new Register(2, 1, 0, &PORTB);
        Register* d = new Register(5, 4, 3, &PORTB);
        Register* e = new Register(2, 1, 0, &PORTC);
        Register* f = new Register(5, 4, 3, &PORTC);

        this->A = 0b00000000;
        this->B = 0b00000000;
        this->C = 0b00000000;
        this->D = 0b00000000;
        this->E = 0b00000000;
        this->F = 0b00000000;

        this->shiftOut(a, this->A);
        this->shiftOut(b, this->B);
        this->shiftOut(c, this->C);
        this->shiftOut(d, this->D);
        this->shiftOut(e, this->E);
        this->shiftOut(f, this->F);

        this->timeToWords();

        this->shiftOut(a, this->A);
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

    void Wordclock::timeToWords() {
        // int minutes = this->time->getMinutes();
        // int hours = this->time->getHours();

        this->A |= 0b1 << TIEN;

        // if (minutes == 0) {

        // }

        // if (minutes == 0) {
        //     strcpy(time, itoa(hours, time, 10));
        //     return strcpy(time, " o' clock"); 
        // }

        // if (minutes == 15) {
        //     return strcpy(time, "quarter past");
        // }

        // if (minutes == 30) {
        //     return strcpy(time, "half past");
        // }

        // if (minutes == 45) {
        //     return strcpy(time, "quarter to");
        // }

        // if (minutes <= 30) {
        //     return strcpy(time, "minutes past ");
        // }

        // if (minutes > 30) {
        //     return strcpy(time, "minutes to");
        // }

        // return "";
    }
}
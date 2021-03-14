#include "include/precomp.h"

void* operator new(size_t objsize) { 
    return malloc(objsize); 
} 

void operator delete(void* obj) { 
    free(obj); 
} 

namespace Wordclock {
    Wordclock::Wordclock() {

        DDRB |= 0B111111;
        DDRD |= 0B11111111;

        Register* a = new Register(0, 1, 2, &PORTB);
        Register* b = new Register(3, 4, 5, &PORTB);
        Register* c = new Register(2, 3, 4, &PORTD);
        Register* d = new Register(5, 6, 7, &PORTD);

        while(true) {
            this->shiftOut(a, 0b11111111);
            this->shiftOut(b, 0b11111111);
            this->shiftOut(c, 0b11111111);
            this->shiftOut(d, 0b11111111);
            _delay_ms(1000);

            this->shiftOut(a, 0b00000000);
            this->shiftOut(b, 0b00000000);
            this->shiftOut(c, 0b00000000);
            this->shiftOut(d, 0b00000000);
            _delay_ms(1000);
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

    const char* Wordclock::timeToWords(int hours, int minutes) {
        char time[20];

        if (minutes == 0) {
            strcpy(time, itoa(hours, time, 10));
            return strcpy(time, " o' clock"); 
        }

        if (minutes == 15) {
            return strcpy(time, "quarter past");
        }

        if (minutes == 30) {
            return strcpy(time, "half past");
        }

        if (minutes == 45) {
            return strcpy(time, "quarter to");
        }

        if (minutes <= 30) {
            return strcpy(time, "minutes past ");
        }

        if (minutes > 30) {
            return strcpy(time, "minutes to");
        }

        return "";
    }
}
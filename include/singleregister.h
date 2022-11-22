#pragma once

#include "register.h"

namespace Wordclock {

    class SingleRegister : public Register {

        public: 
            SingleRegister(int clock, int latch, int data, volatile uint8_t* reg);
            SingleRegister();

            void setRegister(volatile byte* reg);
            volatile byte* getRegister();

            virtual void shiftOut();

        private:
            volatile byte* reg;

        protected:
        
    };
}
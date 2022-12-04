#pragma once

#include "register.h"

namespace Wordclock {

    class SingleRegister : public Register {

        public: 
            SingleRegister(int clock, int latch, int data, volatile uint8_t* reg);
            SingleRegister();

            void setRegister(volatile uint8_t* reg);
            volatile uint8_t* getRegister();

            virtual void shiftOut();

        private:
            volatile uint8_t* reg;

        protected:
        
    };
}
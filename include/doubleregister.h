#pragma once

#include "register.h"

namespace Wordclock {

    class DoubleRegister : public Register {

        public: 
            DoubleRegister(Register* dataRegister, Register* latchRegister, Register* clockRegister, int dataPin, int latchPin, int clockPin);

            void setClockRegister(Register* reg);
            Register* getClockRegister();
            void setLatchRegister(Register* reg);
            Register* getLatchRegister();
            void setDataRegister(Register* reg);
            Register* getDataRegister();

            virtual void shiftOut();

        private:
            Register* clockRegister;
            Register* latchRegister;
            Register* dataRegister;

        protected:
        
    };
}
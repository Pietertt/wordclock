#pragma once

namespace Wordclock {
    
    class Register;
    class Time;
    class Word;

    class Wordclock {

        public: 
            Wordclock();
            void setup();

        private:
            void shiftOut(Register* reg, byte value);
            void doubleShiftOut(Register* a, Register* b, byte value);

            void blink();
            void loop();

            Time* time;

            Register* a;
            Register* b;
            Register* c;
            Register* d;
            Register* e;
            Register* f;
            Register* g;

            Word* words[10];

        protected:

    };
}

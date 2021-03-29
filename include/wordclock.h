#pragma once

namespace Wordclock {
    
    class Register;
    class Time;

    class Wordclock {

        public: 
            Wordclock();
            void setup();

        private:
            void shiftOut(Register* reg, byte value);
            void timeToWords();

            Time* time;

            byte A;
            byte B;
            byte C;
            byte D;
            byte E;
            byte F;

        protected:

    };
}
#pragma once

namespace Wordclock {
    
    class Register;

    class Wordclock {

        public: 
            Wordclock();

        private:
            void shiftOut(Register* reg, byte value);
            const char* timeToWords(int hours, int minutes);

            enum NUMBERS {
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
            };


    };
}
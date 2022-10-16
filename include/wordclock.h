#pragma once

namespace Wordclock {
    
    class Register;
    class Time;

    class Wordclock {

        public: 
            Wordclock();
            void setup();
            void decide_time(Time* time);

        private:
            void shiftOut(Register* reg, byte value);
            void doubleShiftOut(Register* a, Register* b, byte value);

            void blink();
            void loop();
            void clear_display();

            void display_het();
            void display_is();
            void display_eerste_vijf();
            void display_eerste_tien();
            void display_kwart();
            void display_over();
            void display_voor();
            void display_half();
            void display_elf();
            void display_tweede_vijf();
            void display_twee();
            void display_een();
            void display_vier();

            Register* a;
            Register* b;
            Register* c;
            Register* d;
            Register* e;
            Register* f;
            Register* g;

        protected:

    };
}
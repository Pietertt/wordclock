#pragma once

namespace Wordclock {
    
    class Register;
    class DoubleRegister;
    class Word;
    class RTC;

    class Wordclock {

        public: 
            Wordclock();
            void setup();
            void test();
            void allOn();
            void allOff();
            void decide_time();
            void blink();
            void commit();
            void sleep(float milliseconds);

            int getSeconds();
            void setSeconds(int seconds);
            int getMinutes();
            void setMinutes(int minutes);
            int getHour();
            void setHour(int hour);
            void tick();

            void random();

        private:
            Register* a;
            Register* b;
            Register* c;
            Register* d;

            Word* HET;
            Word* IS;
            Word* VIJF;
            Word* TIEN;
            Word* KWART;
            Word* OVER;
            Word* VOOR;
            Word* HALF;
            Word* ELF;
            Word* TWEE;
            Word* TWEEDE_VIJF;
            Word* EEN;
            Word* VIER;
            Word* TWEEDE_TIEN;
            Word* TWAALF;
            Word* DRIE;
            Word* NEGEN;
            Word* ACHT;
            Word* ZES;
            Word* ZEVEN;
            Word* UUR;
            
            Word* words[AMOUNT_OF_WORDS];

            RTC* rtc;

            int seconds = 0;
            int minutes = 0;
            int hour = 0;

            constexpr static int sleepA = (100 - DUTY_CYCLE_LOW) * 100;
            constexpr static int awakeA = DUTY_CYCLE_LOW * 100;
            constexpr static int sleepB = (100 - DUTY_CYCLE_HIGH) * 100;
            constexpr static int awakeB = DUTY_CYCLE_HIGH * 100;

        protected:

    };
}

#pragma once

namespace Wordclock {
    
    class Time {

        public: 
            Time();
            int getSeconds();
            void setSeconds(int seconds);
            int getMinutes();
            void setMinutes(int minutes);
            int getHour();
            void setHour(int hour);
            void tick();

            int counter = 10;
        private:
            int seconds = 0;
            int minutes = 12;
            int hour = 14;
        protected:

    };
}
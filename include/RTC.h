#pragma once

namespace Wordclock {

    class RTC {

        public:
            RTC(uint8_t inSCLK, uint8_t inIO, uint8_t inC_E);
            void initRTC(uint8_t CLK, uint8_t IO, uint8_t ENABLE);
            void DS1302_clock_burst_read( uint8_t *p);
            void DS1302_clock_burst_write( uint8_t *p);
            uint8_t DS1302_read(int address);
            void DS1302_write( int address, uint8_t data);
            void _DS1302_start( void);
            void _DS1302_stop(void);
            uint8_t _DS1302_toggleread( void);
            void _DS1302_togglewrite( uint8_t data, uint8_t release);
            void setDS1302Time(uint8_t seconds, uint8_t minutes, uint8_t hours, uint8_t dayofweek, uint8_t dayofmonth, uint8_t month, int year);
            void updateTime();

            uint8_t SCLK;
            uint8_t IO;
            uint8_t C_E;
            uint8_t seconds;
            uint8_t minutes;
            uint8_t hours;
            uint8_t dayofweek;
            uint8_t dayofmonth;
            uint8_t month;
            int year;

        private:

        protected:

    };
}

#pragma once

#define F_CPU 16000000
#define BLINK_DELAY_MS 1000
#define AMOUNT_OF_WORDS 21

#define uint8_t byte

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
// #include <avr/sfr_defs.h> // -
// #include <SPI.h>
// #include <arduino.h>

// #define DATAOUT 11 //COPI
// #define DATAIN  12 //CIPO
// #define SPICLOCK  13 //sck
// #define CHIPSELECT 10 //cs

// //opcodes
// #define WREN  6
// #define WRDI  4
// #define RDSR  5
// #define WRSR  1
// #define READ  3
// #define WRITE 2

#include "time.h"
#include "wordclock.h"
#include "register.h"
#include "singleregister.h"
#include "doubleregister.h"
#include "word.h"

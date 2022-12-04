#pragma once

#define F_CPU           16000000
#define BLINK_DELAY_MS  1000
#define AMOUNT_OF_WORDS 21
// #define uint8_t uint8_t
#define DUTY_CYCLE_LOW 1
#define DUTY_CYCLE_HIGH 100
#define LOW_POWER_HOUR 16

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <arduino.h>
#include <SPI.h>

#include "time.h"
#include "wordclock.h"
#include "register.h"
#include "singleregister.h"
#include "doubleregister.h"
#include "word.h"

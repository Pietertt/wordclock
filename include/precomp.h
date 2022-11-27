#pragma once

#define F_CPU 16000000
#define BLINK_DELAY_MS 1000
#define AMOUNT_OF_WORDS 21

#define uint8_t byte

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "time.h"
#include "wordclock.h"
#include "register.h"
#include "singleregister.h"
#include "doubleregister.h"
#include "word.h"

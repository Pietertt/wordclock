#pragma once

#define F_CPU 16000000
#define BLINK_DELAY_MS 1000

#define uint8_t byte

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "wordclock.h"
#include "register.h"
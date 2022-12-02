#include "../include/precomp.h"

namespace Wordclock {
    Wordclock::Wordclock() {

    }

    void Wordclock::setup() {
        DDRB |= 0B111111;
        DDRC |= 0B111111;
        DDRD |= 0B11111111;

        this->a = new SingleRegister(2, 1, 0, &PORTC);
        this->b = new DoubleRegister(this->a, this->a, this->a, 0, 1, 2);
        this->c = new DoubleRegister(this->b, this->a, this->a, 0, 3, 4);
        this->d = new DoubleRegister(this->a, this->a, this->a, 5, 6, 7);

        this->a->setData(0b00000000);
        this->b->setData(0b00000000);
        this->c->setData(0b00000000);
        this->d->setData(0b00000000);

        this->commit();

        /*
            HET     IS      VIJF
            TIEN            KWART
            OVER            VOOR
            ELF             HALF
            TWEEDE_VIJF     TWEE
            EEN             VIER
            TWAALF          TWEEDE_TIEN
            DRIE            NEGEN
            ACHT            ZES
            ZEVEN           UUR
        */

        this->HET = new Word(this, this->d, 1);
        this->IS = new Word(this, this->b, 1);
        this->VIJF = new Word(this, this->b, 2);
        this->TIEN = new Word(this, this->d, 7);
        this->KWART = new Word(this, this->b, 3);
        this->OVER = new Word(this, this->d, 6);
        this->VOOR = new Word(this, this->b, 4);
        this->ELF = new Word(this, this->b, 5);
        this->HALF = new Word(this, this->d, 5);
        this->TWEEDE_VIJF = new Word(this, this->d, 4);
        this->TWEE = new Word(this, this->c, 2);
        this->EEN = new Word(this, this->d, 3);
        this->VIER = new Word(this, this->d, 2);
        this->TWAALF = new Word(this, this->c, 4);
        this->TWEEDE_TIEN = new Word(this, this->b, 6);
        this->DRIE = new Word(this, this->c, 5);
        this->NEGEN = new Word(this, this->c, 1);
        this->ACHT = new Word(this, this->c, 6);
        this->ZES = new Word(this, this->b, 7);
        this->ZEVEN = new Word(this, this->c, 7);
        this->UUR = new Word(this, this->c, 3);

        this->words[0] = this->HET;
        this->words[1] = this->IS;
        this->words[2] = this->VIJF;
        this->words[3] = this->TIEN;
        this->words[4] = this->KWART;
        this->words[5] = this->OVER;
        this->words[6] = this->VOOR;
        this->words[7] = this->ELF;
        this->words[8] = this->HALF;
        this->words[9] = this->TWEEDE_VIJF;     
        this->words[10] = this->TWEE;
        this->words[11] = this->EEN;
        this->words[12] = this->VIER;
        this->words[13] = this->TWAALF;
        this->words[14] = this->TWEEDE_TIEN;
        this->words[15] = this->DRIE;
        this->words[16] = this->NEGEN;
        this->words[17] = this->ACHT;
        this->words[18] = this->ZES;
        this->words[19] = this->ZEVEN;
        this->words[20] = this->UUR;
    }

    void Wordclock::test() {
        for (int i = 0; i < AMOUNT_OF_WORDS; i++) {
            this->words[i]->test();
        }

        for (int i = 0; i < 5; i++) {
            this->blink();
        }
    }

    void Wordclock::allOn() {
        for (int i = 0; i < AMOUNT_OF_WORDS; i++) {
            this->words[i]->on();
        }
    }

    void Wordclock::allOff() {
        for (int i = 0; i < AMOUNT_OF_WORDS; i++) {
            this->words[i]->off();
        }
    }

    void Wordclock::blink() {
        this->allOn();
        this->commit();
        _delay_ms(200);

        this->allOff();
        this->commit();
        _delay_ms(200);
    }

    void Wordclock::decide_time(Time* time) {
        int minutes = time->getMinutes();
        int hour = time->getHour();

        if (minutes >= 18) {
            hour++;
        }

        this->HET->on();
        this->IS->on();

        switch (minutes) {
            case 2 ... 7:
                this->VIJF->on();
                this->OVER->on();
                break;
            case 8 ... 12:
                this->TIEN->on();
                this->OVER->on();
                break;
            case 13 ... 17:
                this->KWART->on();
                this->OVER->on();
                break;
            case 18 ... 22:
                this->TIEN->on();
                this->VOOR->on();
                this->HALF->on();
                break;
            case 23 ... 27:
                this->VIJF->on();
                this->VOOR->on();
                this->HALF->on();
                break;
            case 28 ... 32:
                this->HALF->on();
                break;
            case 33 ... 37:
                this->VIJF->on();
                this->OVER->on();
                this->HALF->on();
                break;
            case 38 ... 42:
                this->TIEN->on();
                this->OVER->on();
                this->HALF->on();
                break;
            case 43 ... 47:
                this->KWART->on();
                this->VOOR->on();
                break;
            case 48 ... 52:
                this->TIEN->on();
                this->VOOR->on();
                break;
            case 53 ... 57:
                this->VIJF->on();
                this->VOOR->on();
                break;
            default:
                this->UUR->on();
                break;
        }

        switch(hour) {
            case 1:
            case 13:
                this->EEN->on();
                break;
            case 2:
            case 14:
                this->TWEE->on();
                break;
            case 3:
            case 15:
                this->DRIE->on();
                break;
            case 4:
            case 16:
                this->VIER->on();
                break;
            case 5:
            case 17:
                this->TWEEDE_VIJF->on();
                break;
            case 6:
            case 18:
                this->ZES->on();
                break;
            case 7:
            case 19:
                this->ZEVEN->on();
                break;
            case 8:
            case 20:
                this->ACHT->on();
                break;
            case 9:
            case 21:
                this->NEGEN->on();
                break;
            case 10:
            case 22:
                this->TWEEDE_TIEN->on();
                break;
            case 11:
            case 23:
                this->ELF->on();
                break;
            case 0:
            case 12:
            case 24:
                this->TWAALF->on();
                break;
            default:
                break;
        }
    }

    void Wordclock::commit() {
        // this->a->shiftOut();
        this->b->shiftOut();
        this->c->shiftOut();
        this->d->shiftOut();
    }
}

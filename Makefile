NAME		:= main.ccp
DEVICE		:= atmega328p
PORT		:= /dev/cu.usbmodemFD121
BAUD		:= 115200
OUTPUT		:= bin/main.hex
BIN			:= bin/main.bin
PATH		:= /private/var/folders/jb/tmjxrj3s4jd3cfj0ddpxv16w0000gn/T/AppTranslocation/B1BF58C0-DD8C-425C-8513-9B1679170265/d/Arduino.app/Contents/Java/hardware/tools/avr

compile:
	@$(PATH)/bin/avr-g++ -Wall -g -Os -mmcu=atmega328p -o $(BIN) main.cpp wordclock.cpp register.cpp time.cpp word.cpp -I include
	@$(PATH)/bin/avr-objcopy -j .text -j .data -O ihex $(BIN) $(OUTPUT)

flash:
	@$(PATH)/bin/avrdude -v -p$(DEVICE) -carduino -P$(PORT) -b$(BAUD) -D -Uflash:w:$(OUTPUT) -C/private/var/folders/jb/tmjxrj3s4jd3cfj0ddpxv16w0000gn/T/AppTranslocation/B1BF58C0-DD8C-425C-8513-9B1679170265/d/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf

clean:
	@rm -rf bin/*.bin
	@rm -rf bin/*.hex

run:
	@make compile
	@make flash
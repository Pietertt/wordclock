NAME		:= main.ccp
DEVICE		:= atmega328p
PORT		:= /dev/cu.usbmodemFA121
BAUD		:= 115200
OUTPUT		:= bin/main.hex
BIN			:= bin/main.bin
CONTAINER_ID := $(shell docker container ls  | grep 'wordclock' | awk '{print $$1}')

compile:
	@docker exec -it $(CONTAINER_ID) avr-gcc -Wall -g -Os -mmcu=atmega328p -o $(BIN) main.cpp wordclock.cpp register.cpp time.cpp -I include
	@docker exec -it $(CONTAINER_ID) avr-objcopy -j .text -j .data -O ihex $(BIN) $(OUTPUT)

flash:
	@avrdude -v -p$(DEVICE) -carduino -P$(PORT) -b$(BAUD) -D -Uflash:w:$(OUTPUT)
	@make clean

clean:
	@rm -rf bin/*.bin
	@rm -rf bin/*.hex

run:
	@make compile
	@make flash

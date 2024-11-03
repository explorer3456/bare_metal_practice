CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

# $^ : dependency
# $@ : target
# left hand : target
# right hand : dependency

all: main.o led.o stm32_startup.o final.elf

main.o : main.c
# $(CC) $(CFLAGS) main.c -o main.o
# $(CC) $(CFLAGS) $^ -o $@
	$(CC) $(CFLAGS) -o $@ $^

led.o : led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o : stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm *.o *.elf
load:
	openocd -f board/stm32f4discovery.cfg 

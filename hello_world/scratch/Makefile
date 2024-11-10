CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -std=gnu11 -O0
#LDFLAGS= --specs=nano.specs -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -T stm32_ls.ld -Wl,-Map=final.map
LDFLAGS_SEMI= --specs=rdimon.specs -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -T stm32_ls.ld -Wl,-Map=final.map

# $^ : dependency
# $@ : target
# left hand : target
# right hand : dependency

all: main.o led.o stm32_startup.o my_syscall.o final.elf

semi: main.o led.o stm32_startup.o final_semi.elf


main.o : main.c
# $(CC) $(CFLAGS) main.c -o main.o
# $(CC) $(CFLAGS) $^ -o $@
	$(CC) $(CFLAGS) -o $@ $^

led.o : led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o : stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

my_syscall.o : my_syscall.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o led.o stm32_startup.o my_syscall.o
	$(CC) $(LDFLAGS) -o $@ $^

final_semi.elf: main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS_SEMI) -o $@ $^

clean:
	rm *.o *.elf
load:
	openocd -f board/stm32f4discovery.cfg 

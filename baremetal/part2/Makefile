#LCFLAGS = $(CFLAGS) -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostartfiles
LCFLAGS = $(CFLAGS) -O0 -DRPI2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostartfiles -g
CC = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
OUTPUT_ELF = kernel.elf
OUTPUT_BIN = kernel.img

all: part2.c
	$(CC) $< $(LCFLAGS) -o $(OUTPUT_ELF)
	$(OC) $(OUTPUT_ELF) -O binary $(OUTPUT_BIN)

clean:
	rm kernel.img
	rm kernel.elf


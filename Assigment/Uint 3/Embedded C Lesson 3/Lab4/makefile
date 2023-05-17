# @make file || prebared by Eng Ahmed Maher 
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.S)
AsOBJ= $(As:.s=.o)
Project_name=Learn-in-depth-cortex-m4

all: $(Project_name).bin
	@echo "========Build is done========" 
	@echo "========Prebared By Eng Ahmed Maher========"

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T ls.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).elf.axf
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@ 

$(ProjectName).hex:$(ProjectName).elf
	$(CC)objcopy.exe -O ihex $< $@

clean_all: 
	rm *.o *.elf *.bin	
	
clean: 
	rm *.elf *.bin	
	
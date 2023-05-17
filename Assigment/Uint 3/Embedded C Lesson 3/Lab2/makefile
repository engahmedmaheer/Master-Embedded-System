#prebeard by Eng Ahmed Maher 
#Make File For Machine arm926ej versatilepb
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_Name=Learn-in-depth

all: $(Project_Name).bin
	@echo "===== EVERYTHING DONE  ====="
	@echo "===== prebeard by Eng Ahmed Maher ====="
startup.o: startup.s
	$(CC)as.exe  $(CFLAGS) $< -o $@
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c  $(INCS)   $< -o $@
$(Project_Name).elf: $(OBJ)  $(ASOBJ) 
	$(CC)ld.exe -T ls.ld $(LIBS)  $(OBJ)  -o $@
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
Clean_all: 
	rm *.o *.elf *.bin 
Clean:
	rm  *.elf *.bin  
	@echo "====EVERYTHING CLEAN===="
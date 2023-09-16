################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103x6/AFIO_Program.c \
../STM32F103x6/CLCD_prog.c \
../STM32F103x6/EEPROM_Program.c \
../STM32F103x6/EXTI_Program.c \
../STM32F103x6/GPIO_Program.c \
../STM32F103x6/I2C_Program.c \
../STM32F103x6/KPD_prog.c \
../STM32F103x6/MAX7221_Program.c \
../STM32F103x6/NVIC_Program.c \
../STM32F103x6/RCC_Program.c \
../STM32F103x6/SPI_Program.c \
../STM32F103x6/STK_program.c \
../STM32F103x6/TFT_Program.c \
../STM32F103x6/USART_Program.c 

OBJS += \
./STM32F103x6/AFIO_Program.o \
./STM32F103x6/CLCD_prog.o \
./STM32F103x6/EEPROM_Program.o \
./STM32F103x6/EXTI_Program.o \
./STM32F103x6/GPIO_Program.o \
./STM32F103x6/I2C_Program.o \
./STM32F103x6/KPD_prog.o \
./STM32F103x6/MAX7221_Program.o \
./STM32F103x6/NVIC_Program.o \
./STM32F103x6/RCC_Program.o \
./STM32F103x6/SPI_Program.o \
./STM32F103x6/STK_program.o \
./STM32F103x6/TFT_Program.o \
./STM32F103x6/USART_Program.o 

C_DEPS += \
./STM32F103x6/AFIO_Program.d \
./STM32F103x6/CLCD_prog.d \
./STM32F103x6/EEPROM_Program.d \
./STM32F103x6/EXTI_Program.d \
./STM32F103x6/GPIO_Program.d \
./STM32F103x6/I2C_Program.d \
./STM32F103x6/KPD_prog.d \
./STM32F103x6/MAX7221_Program.d \
./STM32F103x6/NVIC_Program.d \
./STM32F103x6/RCC_Program.d \
./STM32F103x6/SPI_Program.d \
./STM32F103x6/STK_program.d \
./STM32F103x6/TFT_Program.d \
./STM32F103x6/USART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103x6/%.o STM32F103x6/%.su STM32F103x6/%.cyclo: ../STM32F103x6/%.c STM32F103x6/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Learn in Depth/New WS/Drive/STM32F103x6/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103x6

clean-STM32F103x6:
	-$(RM) ./STM32F103x6/AFIO_Program.cyclo ./STM32F103x6/AFIO_Program.d ./STM32F103x6/AFIO_Program.o ./STM32F103x6/AFIO_Program.su ./STM32F103x6/CLCD_prog.cyclo ./STM32F103x6/CLCD_prog.d ./STM32F103x6/CLCD_prog.o ./STM32F103x6/CLCD_prog.su ./STM32F103x6/EEPROM_Program.cyclo ./STM32F103x6/EEPROM_Program.d ./STM32F103x6/EEPROM_Program.o ./STM32F103x6/EEPROM_Program.su ./STM32F103x6/EXTI_Program.cyclo ./STM32F103x6/EXTI_Program.d ./STM32F103x6/EXTI_Program.o ./STM32F103x6/EXTI_Program.su ./STM32F103x6/GPIO_Program.cyclo ./STM32F103x6/GPIO_Program.d ./STM32F103x6/GPIO_Program.o ./STM32F103x6/GPIO_Program.su ./STM32F103x6/I2C_Program.cyclo ./STM32F103x6/I2C_Program.d ./STM32F103x6/I2C_Program.o ./STM32F103x6/I2C_Program.su ./STM32F103x6/KPD_prog.cyclo ./STM32F103x6/KPD_prog.d ./STM32F103x6/KPD_prog.o ./STM32F103x6/KPD_prog.su ./STM32F103x6/MAX7221_Program.cyclo ./STM32F103x6/MAX7221_Program.d ./STM32F103x6/MAX7221_Program.o ./STM32F103x6/MAX7221_Program.su ./STM32F103x6/NVIC_Program.cyclo ./STM32F103x6/NVIC_Program.d ./STM32F103x6/NVIC_Program.o ./STM32F103x6/NVIC_Program.su ./STM32F103x6/RCC_Program.cyclo ./STM32F103x6/RCC_Program.d ./STM32F103x6/RCC_Program.o ./STM32F103x6/RCC_Program.su ./STM32F103x6/SPI_Program.cyclo ./STM32F103x6/SPI_Program.d ./STM32F103x6/SPI_Program.o ./STM32F103x6/SPI_Program.su ./STM32F103x6/STK_program.cyclo ./STM32F103x6/STK_program.d ./STM32F103x6/STK_program.o ./STM32F103x6/STK_program.su ./STM32F103x6/TFT_Program.cyclo ./STM32F103x6/TFT_Program.d ./STM32F103x6/TFT_Program.o ./STM32F103x6/TFT_Program.su ./STM32F103x6/USART_Program.cyclo ./STM32F103x6/USART_Program.d ./STM32F103x6/USART_Program.o ./STM32F103x6/USART_Program.su

.PHONY: clean-STM32F103x6


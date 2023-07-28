################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/MCAL/AFIO_Program.c \
../STM32_F103C6_Drivers/MCAL/EXTI_Program.c \
../STM32_F103C6_Drivers/MCAL/GPIO_Program.c \
../STM32_F103C6_Drivers/MCAL/NVIC_Program.c \
../STM32_F103C6_Drivers/MCAL/STK_program.c 

OBJS += \
./STM32_F103C6_Drivers/MCAL/AFIO_Program.o \
./STM32_F103C6_Drivers/MCAL/EXTI_Program.o \
./STM32_F103C6_Drivers/MCAL/GPIO_Program.o \
./STM32_F103C6_Drivers/MCAL/NVIC_Program.o \
./STM32_F103C6_Drivers/MCAL/STK_program.o 

C_DEPS += \
./STM32_F103C6_Drivers/MCAL/AFIO_Program.d \
./STM32_F103C6_Drivers/MCAL/EXTI_Program.d \
./STM32_F103C6_Drivers/MCAL/GPIO_Program.d \
./STM32_F103C6_Drivers/MCAL/NVIC_Program.d \
./STM32_F103C6_Drivers/MCAL/STK_program.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/MCAL/%.o STM32_F103C6_Drivers/MCAL/%.su STM32_F103C6_Drivers/MCAL/%.cyclo: ../STM32_F103C6_Drivers/MCAL/%.c STM32_F103C6_Drivers/MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/Memorey_MapF103" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/HAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC/HAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC/LIB" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC/MCAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/MCAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/HAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_F103C6_Drivers-2f-MCAL

clean-STM32_F103C6_Drivers-2f-MCAL:
	-$(RM) ./STM32_F103C6_Drivers/MCAL/AFIO_Program.cyclo ./STM32_F103C6_Drivers/MCAL/AFIO_Program.d ./STM32_F103C6_Drivers/MCAL/AFIO_Program.o ./STM32_F103C6_Drivers/MCAL/AFIO_Program.su ./STM32_F103C6_Drivers/MCAL/EXTI_Program.cyclo ./STM32_F103C6_Drivers/MCAL/EXTI_Program.d ./STM32_F103C6_Drivers/MCAL/EXTI_Program.o ./STM32_F103C6_Drivers/MCAL/EXTI_Program.su ./STM32_F103C6_Drivers/MCAL/GPIO_Program.cyclo ./STM32_F103C6_Drivers/MCAL/GPIO_Program.d ./STM32_F103C6_Drivers/MCAL/GPIO_Program.o ./STM32_F103C6_Drivers/MCAL/GPIO_Program.su ./STM32_F103C6_Drivers/MCAL/NVIC_Program.cyclo ./STM32_F103C6_Drivers/MCAL/NVIC_Program.d ./STM32_F103C6_Drivers/MCAL/NVIC_Program.o ./STM32_F103C6_Drivers/MCAL/NVIC_Program.su ./STM32_F103C6_Drivers/MCAL/STK_program.cyclo ./STM32_F103C6_Drivers/MCAL/STK_program.d ./STM32_F103C6_Drivers/MCAL/STK_program.o ./STM32_F103C6_Drivers/MCAL/STK_program.su

.PHONY: clean-STM32_F103C6_Drivers-2f-MCAL


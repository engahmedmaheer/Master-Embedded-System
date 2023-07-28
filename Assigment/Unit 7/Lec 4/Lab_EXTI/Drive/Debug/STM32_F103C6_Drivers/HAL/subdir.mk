################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/HAL/CLCD_prog.c \
../STM32_F103C6_Drivers/HAL/KPD_prog.c 

OBJS += \
./STM32_F103C6_Drivers/HAL/CLCD_prog.o \
./STM32_F103C6_Drivers/HAL/KPD_prog.o 

C_DEPS += \
./STM32_F103C6_Drivers/HAL/CLCD_prog.d \
./STM32_F103C6_Drivers/HAL/KPD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/HAL/%.o STM32_F103C6_Drivers/HAL/%.su STM32_F103C6_Drivers/HAL/%.cyclo: ../STM32_F103C6_Drivers/HAL/%.c STM32_F103C6_Drivers/HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/Memorey_MapF103" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/HAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC/HAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC/LIB" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC/MCAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/MCAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/HAL" -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/MCAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_F103C6_Drivers-2f-HAL

clean-STM32_F103C6_Drivers-2f-HAL:
	-$(RM) ./STM32_F103C6_Drivers/HAL/CLCD_prog.cyclo ./STM32_F103C6_Drivers/HAL/CLCD_prog.d ./STM32_F103C6_Drivers/HAL/CLCD_prog.o ./STM32_F103C6_Drivers/HAL/CLCD_prog.su ./STM32_F103C6_Drivers/HAL/KPD_prog.cyclo ./STM32_F103C6_Drivers/HAL/KPD_prog.d ./STM32_F103C6_Drivers/HAL/KPD_prog.o ./STM32_F103C6_Drivers/HAL/KPD_prog.su

.PHONY: clean-STM32_F103C6_Drivers-2f-HAL


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/GPIO_Program.c 

OBJS += \
./STM32_F103C6_Drivers/GPIO_Program.o 

C_DEPS += \
./STM32_F103C6_Drivers/GPIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/%.o STM32_F103C6_Drivers/%.su STM32_F103C6_Drivers/%.cyclo: ../STM32_F103C6_Drivers/%.c STM32_F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Learn in Depth/CubeIDE_WS/Drive/STM32_F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_F103C6_Drivers

clean-STM32_F103C6_Drivers:
	-$(RM) ./STM32_F103C6_Drivers/GPIO_Program.cyclo ./STM32_F103C6_Drivers/GPIO_Program.d ./STM32_F103C6_Drivers/GPIO_Program.o ./STM32_F103C6_Drivers/GPIO_Program.su

.PHONY: clean-STM32_F103C6_Drivers


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/startup_stm32f072rbtx.s 

OBJS += \
./CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/startup_stm32f072rbtx.o 

S_DEPS += \
./CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/startup_stm32f072rbtx.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/%.o: ../CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/%.s CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-CanOpenSTM32-2f-examples-2f-stm32f0xx_can-2f-Core-2f-Startup

clean-CanOpenSTM32-2f-examples-2f-stm32f0xx_can-2f-Core-2f-Startup:
	-$(RM) ./CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/startup_stm32f072rbtx.d ./CanOpenSTM32/examples/stm32f0xx_can/Core/Startup/startup_stm32f072rbtx.o

.PHONY: clean-CanOpenSTM32-2f-examples-2f-stm32f0xx_can-2f-Core-2f-Startup


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/startup_stm32h735igkx.s 

OBJS += \
./CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/startup_stm32h735igkx.o 

S_DEPS += \
./CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/startup_stm32h735igkx.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/%.o: ../CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/%.s CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-CanOpenSTM32-2f-legacy-2f-stm32h7xx_fdcan-2f-Startup

clean-CanOpenSTM32-2f-legacy-2f-stm32h7xx_fdcan-2f-Startup:
	-$(RM) ./CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/startup_stm32h735igkx.d ./CanOpenSTM32/legacy/stm32h7xx_fdcan/Startup/startup_stm32h735igkx.o

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-stm32h7xx_fdcan-2f-Startup


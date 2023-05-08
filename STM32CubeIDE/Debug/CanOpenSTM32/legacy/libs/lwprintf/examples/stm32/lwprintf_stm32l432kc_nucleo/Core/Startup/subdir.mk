################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/startup_stm32l412kbux.s 

OBJS += \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/startup_stm32l412kbux.o 

S_DEPS += \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/startup_stm32l412kbux.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/%.o: ../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/%.s CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-examples-2f-stm32-2f-lwprintf_stm32l432kc_nucleo-2f-Core-2f-Startup

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-examples-2f-stm32-2f-lwprintf_stm32l432kc_nucleo-2f-Core-2f-Startup:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/startup_stm32l412kbux.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Startup/startup_stm32l412kbux.o

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-examples-2f-stm32-2f-lwprintf_stm32l432kc_nucleo-2f-Core-2f-Startup


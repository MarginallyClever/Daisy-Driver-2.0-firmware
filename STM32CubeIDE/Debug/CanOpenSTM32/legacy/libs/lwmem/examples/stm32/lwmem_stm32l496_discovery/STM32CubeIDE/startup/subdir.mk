################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/startup_stm32l496xx.s 

OBJS += \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/startup_stm32l496xx.o 

S_DEPS += \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/startup_stm32l496xx.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/%.o: ../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/%.s CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-stm32-2f-lwmem_stm32l496_discovery-2f-STM32CubeIDE-2f-startup

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-stm32-2f-lwmem_stm32l496_discovery-2f-STM32CubeIDE-2f-startup:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/startup_stm32l496xx.d ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_stm32l496_discovery/STM32CubeIDE/startup/startup_stm32l496xx.o

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-stm32-2f-lwmem_stm32l496_discovery-2f-STM32CubeIDE-2f-startup


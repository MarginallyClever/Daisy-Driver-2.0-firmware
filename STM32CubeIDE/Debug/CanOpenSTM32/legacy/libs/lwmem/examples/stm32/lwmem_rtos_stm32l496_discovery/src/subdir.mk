################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/main.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/stm32l4xx_it.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/syscalls.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/system_stm32l4xx.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/main.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/stm32l4xx_it.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/syscalls.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/system_stm32l4xx.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/main.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/stm32l4xx_it.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/syscalls.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/%.o CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/%.su: ../CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/%.c CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-stm32-2f-lwmem_rtos_stm32l496_discovery-2f-src

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-stm32-2f-lwmem_rtos_stm32l496_discovery-2f-src:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/main.d ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/main.o ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/main.su ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/stm32l4xx_it.d ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/stm32l4xx_it.o ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/stm32l4xx_it.su ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/syscalls.d ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/syscalls.o ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/syscalls.su ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/system_stm32l4xx.d ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/system_stm32l4xx.o ./CanOpenSTM32/legacy/libs/lwmem/examples/stm32/lwmem_rtos_stm32l496_discovery/src/system_stm32l4xx.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-stm32-2f-lwmem_rtos_stm32l496_discovery-2f-src


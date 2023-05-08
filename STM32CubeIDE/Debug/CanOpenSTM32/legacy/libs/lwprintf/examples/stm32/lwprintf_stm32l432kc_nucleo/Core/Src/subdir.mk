################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/main.c \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_hal_msp.c \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_it.c \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/syscalls.c \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/sysmem.c \
../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/system_stm32l4xx.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/main.o \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_hal_msp.o \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_it.o \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/syscalls.o \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/sysmem.o \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/system_stm32l4xx.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/main.d \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_hal_msp.d \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_it.d \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/syscalls.d \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/sysmem.d \
./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/%.o CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/%.su: ../CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/%.c CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-examples-2f-stm32-2f-lwprintf_stm32l432kc_nucleo-2f-Core-2f-Src

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-examples-2f-stm32-2f-lwprintf_stm32l432kc_nucleo-2f-Core-2f-Src:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/main.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/main.o ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/main.su ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_hal_msp.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_hal_msp.o ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_hal_msp.su ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_it.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_it.o ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/stm32l4xx_it.su ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/syscalls.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/syscalls.o ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/syscalls.su ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/sysmem.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/sysmem.o ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/sysmem.su ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/system_stm32l4xx.d ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/system_stm32l4xx.o ./CanOpenSTM32/legacy/libs/lwprintf/examples/stm32/lwprintf_stm32l432kc_nucleo/Core/Src/system_stm32l4xx.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-examples-2f-stm32-2f-lwprintf_stm32l432kc_nucleo-2f-Core-2f-Src


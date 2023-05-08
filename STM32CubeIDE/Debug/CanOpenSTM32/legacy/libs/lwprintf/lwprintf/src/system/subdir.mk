################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_cmsis_os.c \
../CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_threadx.c \
../CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_win32.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_cmsis_os.o \
./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_threadx.o \
./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_win32.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_cmsis_os.d \
./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_threadx.d \
./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_win32.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/%.o CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/%.su: ../CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/%.c CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-lwprintf-2f-src-2f-system

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-lwprintf-2f-src-2f-system:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_cmsis_os.d ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_cmsis_os.o ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_cmsis_os.su ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_threadx.d ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_threadx.o ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_threadx.su ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_win32.d ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_win32.o ./CanOpenSTM32/legacy/libs/lwprintf/lwprintf/src/system/lwprintf_sys_win32.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwprintf-2f-lwprintf-2f-src-2f-system


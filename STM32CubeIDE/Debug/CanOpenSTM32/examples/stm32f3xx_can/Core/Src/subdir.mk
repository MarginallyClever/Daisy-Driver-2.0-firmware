################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/can.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/gpio.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/main.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/rtc.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_hal_msp.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_it.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/syscalls.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/sysmem.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/system_stm32f3xx.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/tim.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usart.c \
../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usb.c 

OBJS += \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/can.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/gpio.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/main.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/rtc.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_hal_msp.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_it.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/syscalls.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/sysmem.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/system_stm32f3xx.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/tim.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usart.o \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usb.o 

C_DEPS += \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/can.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/gpio.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/main.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/rtc.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_hal_msp.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_it.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/syscalls.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/sysmem.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/system_stm32f3xx.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/tim.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usart.d \
./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usb.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/examples/stm32f3xx_can/Core/Src/%.o CanOpenSTM32/examples/stm32f3xx_can/Core/Src/%.su: ../CanOpenSTM32/examples/stm32f3xx_can/Core/Src/%.c CanOpenSTM32/examples/stm32f3xx_can/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-examples-2f-stm32f3xx_can-2f-Core-2f-Src

clean-CanOpenSTM32-2f-examples-2f-stm32f3xx_can-2f-Core-2f-Src:
	-$(RM) ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/can.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/can.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/can.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/gpio.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/gpio.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/gpio.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/main.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/main.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/main.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/rtc.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/rtc.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/rtc.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_hal_msp.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_hal_msp.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_hal_msp.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_it.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_it.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/stm32f3xx_it.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/syscalls.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/syscalls.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/syscalls.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/sysmem.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/sysmem.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/sysmem.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/system_stm32f3xx.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/system_stm32f3xx.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/system_stm32f3xx.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/tim.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/tim.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/tim.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usart.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usart.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usart.su ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usb.d ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usb.o ./CanOpenSTM32/examples/stm32f3xx_can/Core/Src/usb.su

.PHONY: clean-CanOpenSTM32-2f-examples-2f-stm32f3xx_can-2f-Core-2f-Src


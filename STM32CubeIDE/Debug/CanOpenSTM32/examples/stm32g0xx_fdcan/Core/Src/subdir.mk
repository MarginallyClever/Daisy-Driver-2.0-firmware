################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/adc.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/dac.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/fdcan.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/gpio.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/i2c.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/main.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_hal_msp.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_it.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/syscalls.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/sysmem.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/system_stm32g0xx.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/tim.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usart.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usb_drd_fs.c 

OBJS += \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/adc.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/dac.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/fdcan.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/gpio.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/i2c.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/main.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_hal_msp.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_it.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/syscalls.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/sysmem.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/system_stm32g0xx.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/tim.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usart.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usb_drd_fs.o 

C_DEPS += \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/adc.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/dac.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/fdcan.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/gpio.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/i2c.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/main.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_hal_msp.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_it.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/syscalls.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/sysmem.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/system_stm32g0xx.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/tim.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usart.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usb_drd_fs.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/%.o CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/%.su: ../CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/%.c CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan-2f-Core-2f-Src

clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan-2f-Core-2f-Src:
	-$(RM) ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/adc.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/adc.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/adc.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/dac.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/dac.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/dac.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/fdcan.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/fdcan.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/fdcan.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/gpio.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/gpio.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/gpio.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/i2c.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/i2c.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/i2c.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/main.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/main.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/main.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_hal_msp.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_hal_msp.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_hal_msp.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_it.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_it.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/stm32g0xx_it.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/syscalls.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/syscalls.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/syscalls.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/sysmem.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/sysmem.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/sysmem.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/system_stm32g0xx.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/system_stm32g0xx.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/system_stm32g0xx.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/tim.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/tim.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/tim.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usart.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usart.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usart.su ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usb_drd_fs.d ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usb_drd_fs.o ./CanOpenSTM32/examples/stm32g0xx_fdcan/Core/Src/usb_drd_fs.su

.PHONY: clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan-2f-Core-2f-Src


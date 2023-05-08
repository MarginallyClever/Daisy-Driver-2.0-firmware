################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/CANopenNode/example/CO_driver_blank.c \
../CanOpenSTM32/CANopenNode/example/CO_storageBlank.c \
../CanOpenSTM32/CANopenNode/example/OD.c \
../CanOpenSTM32/CANopenNode/example/main_blank.c 

OBJS += \
./CanOpenSTM32/CANopenNode/example/CO_driver_blank.o \
./CanOpenSTM32/CANopenNode/example/CO_storageBlank.o \
./CanOpenSTM32/CANopenNode/example/OD.o \
./CanOpenSTM32/CANopenNode/example/main_blank.o 

C_DEPS += \
./CanOpenSTM32/CANopenNode/example/CO_driver_blank.d \
./CanOpenSTM32/CANopenNode/example/CO_storageBlank.d \
./CanOpenSTM32/CANopenNode/example/OD.d \
./CanOpenSTM32/CANopenNode/example/main_blank.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/CANopenNode/example/%.o CanOpenSTM32/CANopenNode/example/%.su: ../CanOpenSTM32/CANopenNode/example/%.c CanOpenSTM32/CANopenNode/example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-CANopenNode-2f-example

clean-CanOpenSTM32-2f-CANopenNode-2f-example:
	-$(RM) ./CanOpenSTM32/CANopenNode/example/CO_driver_blank.d ./CanOpenSTM32/CANopenNode/example/CO_driver_blank.o ./CanOpenSTM32/CANopenNode/example/CO_driver_blank.su ./CanOpenSTM32/CANopenNode/example/CO_storageBlank.d ./CanOpenSTM32/CANopenNode/example/CO_storageBlank.o ./CanOpenSTM32/CANopenNode/example/CO_storageBlank.su ./CanOpenSTM32/CANopenNode/example/OD.d ./CanOpenSTM32/CANopenNode/example/OD.o ./CanOpenSTM32/CANopenNode/example/OD.su ./CanOpenSTM32/CANopenNode/example/main_blank.d ./CanOpenSTM32/CANopenNode/example/main_blank.o ./CanOpenSTM32/CANopenNode/example/main_blank.su

.PHONY: clean-CanOpenSTM32-2f-CANopenNode-2f-example


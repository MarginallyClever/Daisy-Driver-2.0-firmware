################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/source/CO_driver_stm32h735g-dk.c \
../CanOpenSTM32/legacy/source/OD.c \
../CanOpenSTM32/legacy/source/comm_stm32h735g-dk.c 

OBJS += \
./CanOpenSTM32/legacy/source/CO_driver_stm32h735g-dk.o \
./CanOpenSTM32/legacy/source/OD.o \
./CanOpenSTM32/legacy/source/comm_stm32h735g-dk.o 

C_DEPS += \
./CanOpenSTM32/legacy/source/CO_driver_stm32h735g-dk.d \
./CanOpenSTM32/legacy/source/OD.d \
./CanOpenSTM32/legacy/source/comm_stm32h735g-dk.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/source/%.o CanOpenSTM32/legacy/source/%.su: ../CanOpenSTM32/legacy/source/%.c CanOpenSTM32/legacy/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-source

clean-CanOpenSTM32-2f-legacy-2f-source:
	-$(RM) ./CanOpenSTM32/legacy/source/CO_driver_stm32h735g-dk.d ./CanOpenSTM32/legacy/source/CO_driver_stm32h735g-dk.o ./CanOpenSTM32/legacy/source/CO_driver_stm32h735g-dk.su ./CanOpenSTM32/legacy/source/OD.d ./CanOpenSTM32/legacy/source/OD.o ./CanOpenSTM32/legacy/source/OD.su ./CanOpenSTM32/legacy/source/comm_stm32h735g-dk.d ./CanOpenSTM32/legacy/source/comm_stm32h735g-dk.o ./CanOpenSTM32/legacy/source/comm_stm32h735g-dk.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-source


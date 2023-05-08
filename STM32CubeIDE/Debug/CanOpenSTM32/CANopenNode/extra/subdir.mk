################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/CANopenNode/extra/CO_trace.c 

OBJS += \
./CanOpenSTM32/CANopenNode/extra/CO_trace.o 

C_DEPS += \
./CanOpenSTM32/CANopenNode/extra/CO_trace.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/CANopenNode/extra/%.o CanOpenSTM32/CANopenNode/extra/%.su CanOpenSTM32/CANopenNode/extra/%.cyclo: ../CanOpenSTM32/CANopenNode/extra/%.c CanOpenSTM32/CANopenNode/extra/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-CANopenNode-2f-extra

clean-CanOpenSTM32-2f-CANopenNode-2f-extra:
	-$(RM) ./CanOpenSTM32/CANopenNode/extra/CO_trace.cyclo ./CanOpenSTM32/CANopenNode/extra/CO_trace.d ./CanOpenSTM32/CANopenNode/extra/CO_trace.o ./CanOpenSTM32/CANopenNode/extra/CO_trace.su

.PHONY: clean-CanOpenSTM32-2f-CANopenNode-2f-extra


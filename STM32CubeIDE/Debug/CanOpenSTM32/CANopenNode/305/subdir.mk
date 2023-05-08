################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/CANopenNode/305/CO_LSSmaster.c \
../CanOpenSTM32/CANopenNode/305/CO_LSSslave.c 

OBJS += \
./CanOpenSTM32/CANopenNode/305/CO_LSSmaster.o \
./CanOpenSTM32/CANopenNode/305/CO_LSSslave.o 

C_DEPS += \
./CanOpenSTM32/CANopenNode/305/CO_LSSmaster.d \
./CanOpenSTM32/CANopenNode/305/CO_LSSslave.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/CANopenNode/305/%.o CanOpenSTM32/CANopenNode/305/%.su CanOpenSTM32/CANopenNode/305/%.cyclo: ../CanOpenSTM32/CANopenNode/305/%.c CanOpenSTM32/CANopenNode/305/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-CANopenNode-2f-305

clean-CanOpenSTM32-2f-CANopenNode-2f-305:
	-$(RM) ./CanOpenSTM32/CANopenNode/305/CO_LSSmaster.cyclo ./CanOpenSTM32/CANopenNode/305/CO_LSSmaster.d ./CanOpenSTM32/CANopenNode/305/CO_LSSmaster.o ./CanOpenSTM32/CANopenNode/305/CO_LSSmaster.su ./CanOpenSTM32/CANopenNode/305/CO_LSSslave.cyclo ./CanOpenSTM32/CANopenNode/305/CO_LSSslave.d ./CanOpenSTM32/CANopenNode/305/CO_LSSslave.o ./CanOpenSTM32/CANopenNode/305/CO_LSSslave.su

.PHONY: clean-CanOpenSTM32-2f-CANopenNode-2f-305


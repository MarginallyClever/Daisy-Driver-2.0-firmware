################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/CANopenNode/301/CO_Emergency.c \
../CanOpenSTM32/CANopenNode/301/CO_HBconsumer.c \
../CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.c \
../CanOpenSTM32/CANopenNode/301/CO_ODinterface.c \
../CanOpenSTM32/CANopenNode/301/CO_PDO.c \
../CanOpenSTM32/CANopenNode/301/CO_SDOclient.c \
../CanOpenSTM32/CANopenNode/301/CO_SDOserver.c \
../CanOpenSTM32/CANopenNode/301/CO_SYNC.c \
../CanOpenSTM32/CANopenNode/301/CO_TIME.c \
../CanOpenSTM32/CANopenNode/301/CO_fifo.c \
../CanOpenSTM32/CANopenNode/301/crc16-ccitt.c 

OBJS += \
./CanOpenSTM32/CANopenNode/301/CO_Emergency.o \
./CanOpenSTM32/CANopenNode/301/CO_HBconsumer.o \
./CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.o \
./CanOpenSTM32/CANopenNode/301/CO_ODinterface.o \
./CanOpenSTM32/CANopenNode/301/CO_PDO.o \
./CanOpenSTM32/CANopenNode/301/CO_SDOclient.o \
./CanOpenSTM32/CANopenNode/301/CO_SDOserver.o \
./CanOpenSTM32/CANopenNode/301/CO_SYNC.o \
./CanOpenSTM32/CANopenNode/301/CO_TIME.o \
./CanOpenSTM32/CANopenNode/301/CO_fifo.o \
./CanOpenSTM32/CANopenNode/301/crc16-ccitt.o 

C_DEPS += \
./CanOpenSTM32/CANopenNode/301/CO_Emergency.d \
./CanOpenSTM32/CANopenNode/301/CO_HBconsumer.d \
./CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.d \
./CanOpenSTM32/CANopenNode/301/CO_ODinterface.d \
./CanOpenSTM32/CANopenNode/301/CO_PDO.d \
./CanOpenSTM32/CANopenNode/301/CO_SDOclient.d \
./CanOpenSTM32/CANopenNode/301/CO_SDOserver.d \
./CanOpenSTM32/CANopenNode/301/CO_SYNC.d \
./CanOpenSTM32/CANopenNode/301/CO_TIME.d \
./CanOpenSTM32/CANopenNode/301/CO_fifo.d \
./CanOpenSTM32/CANopenNode/301/crc16-ccitt.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/CANopenNode/301/%.o CanOpenSTM32/CANopenNode/301/%.su CanOpenSTM32/CANopenNode/301/%.cyclo: ../CanOpenSTM32/CANopenNode/301/%.c CanOpenSTM32/CANopenNode/301/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-CANopenNode-2f-301

clean-CanOpenSTM32-2f-CANopenNode-2f-301:
	-$(RM) ./CanOpenSTM32/CANopenNode/301/CO_Emergency.cyclo ./CanOpenSTM32/CANopenNode/301/CO_Emergency.d ./CanOpenSTM32/CANopenNode/301/CO_Emergency.o ./CanOpenSTM32/CANopenNode/301/CO_Emergency.su ./CanOpenSTM32/CANopenNode/301/CO_HBconsumer.cyclo ./CanOpenSTM32/CANopenNode/301/CO_HBconsumer.d ./CanOpenSTM32/CANopenNode/301/CO_HBconsumer.o ./CanOpenSTM32/CANopenNode/301/CO_HBconsumer.su ./CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.cyclo ./CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.d ./CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.o ./CanOpenSTM32/CANopenNode/301/CO_NMT_Heartbeat.su ./CanOpenSTM32/CANopenNode/301/CO_ODinterface.cyclo ./CanOpenSTM32/CANopenNode/301/CO_ODinterface.d ./CanOpenSTM32/CANopenNode/301/CO_ODinterface.o ./CanOpenSTM32/CANopenNode/301/CO_ODinterface.su ./CanOpenSTM32/CANopenNode/301/CO_PDO.cyclo ./CanOpenSTM32/CANopenNode/301/CO_PDO.d ./CanOpenSTM32/CANopenNode/301/CO_PDO.o ./CanOpenSTM32/CANopenNode/301/CO_PDO.su ./CanOpenSTM32/CANopenNode/301/CO_SDOclient.cyclo ./CanOpenSTM32/CANopenNode/301/CO_SDOclient.d ./CanOpenSTM32/CANopenNode/301/CO_SDOclient.o ./CanOpenSTM32/CANopenNode/301/CO_SDOclient.su ./CanOpenSTM32/CANopenNode/301/CO_SDOserver.cyclo ./CanOpenSTM32/CANopenNode/301/CO_SDOserver.d ./CanOpenSTM32/CANopenNode/301/CO_SDOserver.o ./CanOpenSTM32/CANopenNode/301/CO_SDOserver.su ./CanOpenSTM32/CANopenNode/301/CO_SYNC.cyclo ./CanOpenSTM32/CANopenNode/301/CO_SYNC.d ./CanOpenSTM32/CANopenNode/301/CO_SYNC.o ./CanOpenSTM32/CANopenNode/301/CO_SYNC.su ./CanOpenSTM32/CANopenNode/301/CO_TIME.cyclo ./CanOpenSTM32/CANopenNode/301/CO_TIME.d ./CanOpenSTM32/CANopenNode/301/CO_TIME.o ./CanOpenSTM32/CANopenNode/301/CO_TIME.su ./CanOpenSTM32/CANopenNode/301/CO_fifo.cyclo ./CanOpenSTM32/CANopenNode/301/CO_fifo.d ./CanOpenSTM32/CANopenNode/301/CO_fifo.o ./CanOpenSTM32/CANopenNode/301/CO_fifo.su ./CanOpenSTM32/CANopenNode/301/crc16-ccitt.cyclo ./CanOpenSTM32/CANopenNode/301/crc16-ccitt.d ./CanOpenSTM32/CANopenNode/301/crc16-ccitt.o ./CanOpenSTM32/CANopenNode/301/crc16-ccitt.su

.PHONY: clean-CanOpenSTM32-2f-CANopenNode-2f-301


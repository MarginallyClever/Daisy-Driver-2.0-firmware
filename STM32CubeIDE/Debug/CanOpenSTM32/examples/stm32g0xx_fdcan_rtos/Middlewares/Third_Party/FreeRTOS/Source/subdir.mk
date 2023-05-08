################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/list.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/queue.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/list.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/queue.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/list.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/queue.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/%.o CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/%.su: ../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/%.c CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan_rtos-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan_rtos-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/croutine.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/croutine.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/croutine.su ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/event_groups.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/event_groups.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/event_groups.su ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/list.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/list.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/list.su ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/queue.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/queue.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/queue.su ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.su ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/tasks.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/tasks.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/tasks.su ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/timers.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/timers.o ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Middlewares/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan_rtos-2f-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source


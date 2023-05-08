################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_dma.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_exti.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_gpio.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_lpuart.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_pwr.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_rcc.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_usart.c \
../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_utils.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_dma.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_exti.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_gpio.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_lpuart.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_pwr.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_rcc.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_usart.o \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_utils.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_dma.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_exti.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_gpio.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_lpuart.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_pwr.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_rcc.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_usart.d \
./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/%.o CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/%.su: ../CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/%.c CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-lib-2f-st-2f-STM32L4xx_HAL_Driver-2f-Src

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-lib-2f-st-2f-STM32L4xx_HAL_Driver-2f-Src:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_dma.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_dma.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_dma.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_exti.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_exti.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_exti.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_gpio.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_gpio.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_gpio.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_lpuart.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_lpuart.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_lpuart.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_pwr.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_pwr.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_pwr.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_rcc.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_rcc.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_rcc.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_usart.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_usart.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_usart.su ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_utils.d ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_utils.o ./CanOpenSTM32/legacy/libs/lwmem/examples/lib/st/STM32L4xx_HAL_Driver/Src/stm32l4xx_ll_utils.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-examples-2f-lib-2f-st-2f-STM32L4xx_HAL_Driver-2f-Src


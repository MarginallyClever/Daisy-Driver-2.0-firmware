################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_1.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_2.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_dma_skip.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_events.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_index.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_minimal.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_1.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_2.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_thread_safety.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size.c \
../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size_log.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_1.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_2.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_dma_skip.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_events.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_index.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_minimal.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_1.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_2.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_thread_safety.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size.o \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size_log.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_1.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_2.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_dma_skip.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_events.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_index.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_minimal.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_1.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_2.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_thread_safety.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size.d \
./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size_log.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/%.o CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/%.su: ../CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/%.c CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-docs-2f-examples_src

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-docs-2f-examples_src:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_1.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_1.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_1.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_2.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_2.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_advance_2.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_dma_skip.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_dma_skip.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_dma_skip.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_events.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_events.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_events.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_index.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_index.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_index.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_minimal.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_minimal.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_minimal.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_1.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_1.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_1.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_2.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_2.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_skip_2.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_thread_safety.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_thread_safety.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_thread_safety.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size.su ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size_log.d ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size_log.o ./CanOpenSTM32/legacy/libs/lwrb/docs/examples_src/example_tt_buff_size_log.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-docs-2f-examples_src


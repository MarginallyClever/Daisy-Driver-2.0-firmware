################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_Test.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_TestRunner.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_output_Spy.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_Test.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_TestRunner.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_output_Spy.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_Test.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_TestRunner.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_output_Spy.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/%.o CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/%.su: ../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/%.c CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-third_party-2f-Unity-2f-extras-2f-memory-2f-test

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-third_party-2f-Unity-2f-extras-2f-memory-2f-test:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_Test.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_Test.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_Test.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_TestRunner.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_TestRunner.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_memory_TestRunner.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_output_Spy.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_output_Spy.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/extras/memory/test/unity_output_Spy.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-third_party-2f-Unity-2f-extras-2f-memory-2f-test


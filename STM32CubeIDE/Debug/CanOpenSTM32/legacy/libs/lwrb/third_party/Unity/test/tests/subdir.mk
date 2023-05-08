################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_arrays.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_core.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_doubles.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_floats.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers_64.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_memory.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_parameterized.c \
../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_strings.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_arrays.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_core.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_doubles.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_floats.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers_64.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_memory.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_parameterized.o \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_strings.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_arrays.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_core.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_doubles.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_floats.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers_64.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_memory.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_parameterized.d \
./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_strings.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/%.o CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/%.su: ../CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/%.c CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-third_party-2f-Unity-2f-test-2f-tests

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-third_party-2f-Unity-2f-test-2f-tests:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_arrays.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_arrays.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_arrays.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_core.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_core.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_core.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_doubles.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_doubles.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_doubles.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_floats.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_floats.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_floats.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers_64.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers_64.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_integers_64.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_memory.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_memory.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_memory.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_parameterized.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_parameterized.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_parameterized.su ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_strings.d ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_strings.o ./CanOpenSTM32/legacy/libs/lwrb/third_party/Unity/test/tests/test_unity_strings.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwrb-2f-third_party-2f-Unity-2f-test-2f-tests


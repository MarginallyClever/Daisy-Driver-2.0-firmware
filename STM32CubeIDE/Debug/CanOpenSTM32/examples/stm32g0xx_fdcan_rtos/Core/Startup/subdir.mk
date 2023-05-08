################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/startup_stm32g0c1vetx.s 

OBJS += \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/startup_stm32g0c1vetx.o 

S_DEPS += \
./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/startup_stm32g0c1vetx.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/%.o: ../CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/%.s CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan_rtos-2f-Core-2f-Startup

clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan_rtos-2f-Core-2f-Startup:
	-$(RM) ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/startup_stm32g0c1vetx.d ./CanOpenSTM32/examples/stm32g0xx_fdcan_rtos/Core/Startup/startup_stm32g0c1vetx.o

.PHONY: clean-CanOpenSTM32-2f-examples-2f-stm32g0xx_fdcan_rtos-2f-Core-2f-Startup


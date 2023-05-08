################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include USB_DEVICE/Target/subdir.mk
-include USB_DEVICE/App/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Core/Src/subdir.mk
-include Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include CanOpenSTM32/CANopenNode_STM32/subdir.mk
-include CanOpenSTM32/CANopenNode/storage/subdir.mk
-include CanOpenSTM32/CANopenNode/extra/subdir.mk
-include CanOpenSTM32/CANopenNode/309/subdir.mk
-include CanOpenSTM32/CANopenNode/305/subdir.mk
-include CanOpenSTM32/CANopenNode/304/subdir.mk
-include CanOpenSTM32/CANopenNode/303/subdir.mk
-include CanOpenSTM32/CANopenNode/301/subdir.mk
-include CanOpenSTM32/CANopenNode/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Daisy Driver 3
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Daisy\ Driver\ 3.elf \

MAP_FILES += \
Daisy\ Driver\ 3.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Daisy\ Driver\ 3.list \


# All Target
all: main-build

# Main-build Target
main-build: Daisy\ Driver\ 3.elf secondary-outputs

# Tool invocations
Daisy\ Driver\ 3.elf Daisy\ Driver\ 3.map: $(OBJS) $(USER_OBJS) C:\Users\aggra\Desktop\robots\Sixi\ 3\actuator\ 2021-feb\arduino_firmware\Daisy-Driver-2.0-firmware\STM32CubeIDE\STM32F405RGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Daisy Driver 3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\aggra\Desktop\robots\Sixi 3\actuator 2021-feb\arduino_firmware\Daisy-Driver-2.0-firmware\STM32CubeIDE\STM32F405RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Daisy Driver 3.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Daisy\ Driver\ 3.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Daisy Driver 3.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Daisy\ Driver\ 3.elf Daisy\ Driver\ 3.list Daisy\ Driver\ 3.map Daisy\\ Driver\\ 3.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

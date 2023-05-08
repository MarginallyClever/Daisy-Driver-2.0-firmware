################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_alloc_from_region.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_minimal.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log_2.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_new_size_smaller_fragmented.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_log.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions.c \
../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions_custom.c 

OBJS += \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_alloc_from_region.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_minimal.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log_2.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_new_size_smaller_fragmented.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_log.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions.o \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions_custom.o 

C_DEPS += \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_alloc_from_region.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_minimal.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log_2.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_new_size_smaller_fragmented.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_log.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions.d \
./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions_custom.d 


# Each subdirectory must supply rules for building sources it contributes
CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/%.o CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/%.su: ../CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/%.c CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode_STM32" -I"C:/Users/aggra/Desktop/robots/Sixi 3/actuator 2021-feb/arduino_firmware/Daisy-Driver-2.0-firmware/STM32CubeIDE/CanOpenSTM32/CANopenNode" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-docs-2f-examples_src

clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-docs-2f-examples_src:
	-$(RM) ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_alloc_from_region.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_alloc_from_region.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_alloc_from_region.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_minimal.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_minimal.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_minimal.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log_2.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log_2.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_custom_realloc_log_2.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_1_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_2_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3a_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3b_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3c_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_3d_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_enlarge_full_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_first_malloc_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_new_size_smaller_fragmented.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_new_size_smaller_fragmented.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_new_size_smaller_fragmented.su
	-$(RM) ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_region_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_fragmented_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_log.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_log.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_realloc_shrink_log.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions.su ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions_custom.d ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions_custom.o ./CanOpenSTM32/legacy/libs/lwmem/docs/examples_src/example_regions_definitions_custom.su

.PHONY: clean-CanOpenSTM32-2f-legacy-2f-libs-2f-lwmem-2f-docs-2f-examples_src


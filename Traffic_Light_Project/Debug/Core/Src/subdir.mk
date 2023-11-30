################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/f_button.c \
../Core/Src/f_display_LED.c \
../Core/Src/f_global.c \
../Core/Src/f_timer.c \
../Core/Src/f_uart.c \
../Core/Src/fsm_auto_mode.c \
../Core/Src/fsm_manual_mode.c \
../Core/Src/fsm_pedestrian_mode.c \
../Core/Src/fsm_tuning_mode.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/f_button.o \
./Core/Src/f_display_LED.o \
./Core/Src/f_global.o \
./Core/Src/f_timer.o \
./Core/Src/f_uart.o \
./Core/Src/fsm_auto_mode.o \
./Core/Src/fsm_manual_mode.o \
./Core/Src/fsm_pedestrian_mode.o \
./Core/Src/fsm_tuning_mode.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/f_button.d \
./Core/Src/f_display_LED.d \
./Core/Src/f_global.d \
./Core/Src/f_timer.d \
./Core/Src/f_uart.d \
./Core/Src/fsm_auto_mode.d \
./Core/Src/fsm_manual_mode.d \
./Core/Src/fsm_pedestrian_mode.d \
./Core/Src/fsm_tuning_mode.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


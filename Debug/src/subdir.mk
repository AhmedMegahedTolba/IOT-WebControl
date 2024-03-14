################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AIOT_Prog.c \
../src/GPIO_Cfg.c \
../src/GPIO_Prog.c \
../src/HDAC_Prog.c \
../src/HLED__MATRIX_Prog.c \
../src/NVIC_Prog.c \
../src/RCC_Prog.c \
../src/S2P_Prog.c \
../src/SPI_Prog.c \
../src/SYSTIC_Prog.c \
../src/Strings_Service.c \
../src/TFT_Prog.c \
../src/UART_Prog.c \
../src/WIFI_Prog.c \
../src/main.c 

OBJS += \
./src/AIOT_Prog.o \
./src/GPIO_Cfg.o \
./src/GPIO_Prog.o \
./src/HDAC_Prog.o \
./src/HLED__MATRIX_Prog.o \
./src/NVIC_Prog.o \
./src/RCC_Prog.o \
./src/S2P_Prog.o \
./src/SPI_Prog.o \
./src/SYSTIC_Prog.o \
./src/Strings_Service.o \
./src/TFT_Prog.o \
./src/UART_Prog.o \
./src/WIFI_Prog.o \
./src/main.o 

C_DEPS += \
./src/AIOT_Prog.d \
./src/GPIO_Cfg.d \
./src/GPIO_Prog.d \
./src/HDAC_Prog.d \
./src/HLED__MATRIX_Prog.d \
./src/NVIC_Prog.d \
./src/RCC_Prog.d \
./src/S2P_Prog.d \
./src/SPI_Prog.d \
./src/SYSTIC_Prog.d \
./src/Strings_Service.d \
./src/TFT_Prog.d \
./src/UART_Prog.d \
./src/WIFI_Prog.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=16000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



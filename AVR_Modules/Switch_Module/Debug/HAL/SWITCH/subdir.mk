################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SWITCH/SW_Config.c \
../HAL/SWITCH/SW_Prog.c 

OBJS += \
./HAL/SWITCH/SW_Config.o \
./HAL/SWITCH/SW_Prog.o 

C_DEPS += \
./HAL/SWITCH/SW_Config.d \
./HAL/SWITCH/SW_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SWITCH/%.o: ../HAL/SWITCH/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



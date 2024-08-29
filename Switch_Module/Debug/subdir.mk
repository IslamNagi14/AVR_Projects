################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../LED_congif.c \
../LED_prog.c \
../SW_Config.c \
../SW_Prog.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./LED_congif.o \
./LED_prog.o \
./SW_Config.o \
./SW_Prog.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./LED_congif.d \
./LED_prog.d \
./SW_Config.d \
./SW_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



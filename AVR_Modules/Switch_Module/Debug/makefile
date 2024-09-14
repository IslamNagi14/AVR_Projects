################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/SWITCH/subdir.mk
-include HAL/LED/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Switch_Module.lss \

FLASH_IMAGE += \
Switch_Module.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Switch_Module.elf secondary-outputs

# Tool invocations
Switch_Module.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Switch_Module.map -mmcu=atmega32 -o "Switch_Module.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Switch_Module.lss: Switch_Module.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Switch_Module.elf  >"Switch_Module.lss"
	@echo 'Finished building: $@'
	@echo ' '

Switch_Module.hex: Switch_Module.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Switch_Module.elf  "Switch_Module.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Switch_Module.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Switch_Module.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Switch_Module.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

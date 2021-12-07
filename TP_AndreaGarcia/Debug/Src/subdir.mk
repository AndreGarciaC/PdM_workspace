################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Include" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/BSP/STM32F4xx_Nucleo_144" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/Core/Inc" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Src" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/API" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/API/Inc" -I"D:/Andrea/CESE/PdM_workspace/TP_AndreaGarcia/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o

.PHONY: clean-Src


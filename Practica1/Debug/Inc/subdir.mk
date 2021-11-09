################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/API_delay.c 

OBJS += \
./Inc/API_delay.o 

C_DEPS += \
./Inc/API_delay.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/andrea/CESE/PdM/PdM_workspace/Practica1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/Practica1/Drivers/CMSIS/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/Practica1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/Practica1/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/andrea/CESE/PdM/PdM_workspace/Practica1/Drivers/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


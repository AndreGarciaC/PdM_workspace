################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/option/ccsbcs.c \
../Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./Middlewares/Third_Party/FatFs/src/option/ccsbcs.o \
./Middlewares/Third_Party/FatFs/src/option/syscall.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/option/ccsbcs.d \
./Middlewares/Third_Party/FatFs/src/option/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/option/%.o: ../Middlewares/Third_Party/FatFs/src/option/%.c Middlewares/Third_Party/FatFs/src/option/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/Core/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Src" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API/Src" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/FATFS/App" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/FATFS/Target" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Middlewares/Third_Party/FatFs/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


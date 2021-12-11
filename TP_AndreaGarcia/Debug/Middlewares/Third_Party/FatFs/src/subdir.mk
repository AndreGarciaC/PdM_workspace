################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/diskio.c \
../Middlewares/Third_Party/FatFs/src/ff.c \
../Middlewares/Third_Party/FatFs/src/ff_gen_drv.c 

OBJS += \
./Middlewares/Third_Party/FatFs/src/diskio.o \
./Middlewares/Third_Party/FatFs/src/ff.o \
./Middlewares/Third_Party/FatFs/src/ff_gen_drv.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/diskio.d \
./Middlewares/Third_Party/FatFs/src/ff.d \
./Middlewares/Third_Party/FatFs/src/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/%.o: ../Middlewares/Third_Party/FatFs/src/%.c Middlewares/Third_Party/FatFs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/Core/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Src" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API/Src" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/FATFS/App" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/FATFS/Target" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Middlewares/Third_Party/FatFs/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


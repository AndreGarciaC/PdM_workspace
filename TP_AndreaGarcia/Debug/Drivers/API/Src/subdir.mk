################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_debounce.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/MEF.c \
../Drivers/API/Src/TESTER_SD.c \
../Drivers/API/Src/TESTER_uart.c 

OBJS += \
./Drivers/API/Src/API_debounce.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/MEF.o \
./Drivers/API/Src/TESTER_SD.o \
./Drivers/API/Src/TESTER_uart.o 

C_DEPS += \
./Drivers/API/Src/API_debounce.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/MEF.d \
./Drivers/API/Src/TESTER_SD.d \
./Drivers/API/Src/TESTER_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/Core/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Src" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API/Inc" -I"/home/andrea/CESE/PdM/PdM_workspace/TP_AndreaGarcia/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Engine.cpp \
../src/Generalization.cpp \
../src/Player.cpp \
../src/Rules.cpp 

OBJS += \
./src/Engine.o \
./src/Generalization.o \
./src/Player.o \
./src/Rules.o 

CPP_DEPS += \
./src/Engine.d \
./src/Generalization.d \
./src/Player.d \
./src/Rules.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



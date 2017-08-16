################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/shader/shader_object.cpp \
../src/shader/shader_program.cpp 

OBJS += \
./src/shader/shader_object.o \
./src/shader/shader_program.o 

CPP_DEPS += \
./src/shader/shader_object.d \
./src/shader/shader_program.d 


# Each subdirectory must supply rules for building sources it contributes
src/shader/%.o: ../src/shader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -I/usr/local/include/bullet -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



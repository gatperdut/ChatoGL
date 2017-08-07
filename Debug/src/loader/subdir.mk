################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/loader/mesh.cpp \
../src/loader/model.cpp 

OBJS += \
./src/loader/mesh.o \
./src/loader/model.o 

CPP_DEPS += \
./src/loader/mesh.d \
./src/loader/model.d 


# Each subdirectory must supply rules for building sources it contributes
src/loader/%.o: ../src/loader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/loader/collision_mesh.cpp \
../src/loader/model.cpp \
../src/loader/model_mesh.cpp 

OBJS += \
./src/loader/collision_mesh.o \
./src/loader/model.o \
./src/loader/model_mesh.o 

CPP_DEPS += \
./src/loader/collision_mesh.d \
./src/loader/model.d \
./src/loader/model_mesh.d 


# Each subdirectory must supply rules for building sources it contributes
src/loader/%.o: ../src/loader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -I/usr/local/include/bullet -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



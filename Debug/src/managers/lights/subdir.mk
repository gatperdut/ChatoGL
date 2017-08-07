################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/managers/lights/directional.cpp \
../src/managers/lights/main.cpp \
../src/managers/lights/point.cpp \
../src/managers/lights/spot.cpp 

OBJS += \
./src/managers/lights/directional.o \
./src/managers/lights/main.o \
./src/managers/lights/point.o \
./src/managers/lights/spot.o 

CPP_DEPS += \
./src/managers/lights/directional.d \
./src/managers/lights/main.d \
./src/managers/lights/point.d \
./src/managers/lights/spot.d 


# Each subdirectory must supply rules for building sources it contributes
src/managers/lights/%.o: ../src/managers/lights/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



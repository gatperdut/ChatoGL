################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/light/directional_light.cpp \
../src/light/point_light.cpp \
../src/light/spot_light.cpp 

OBJS += \
./src/light/directional_light.o \
./src/light/point_light.o \
./src/light/spot_light.o 

CPP_DEPS += \
./src/light/directional_light.d \
./src/light/point_light.d \
./src/light/spot_light.d 


# Each subdirectory must supply rules for building sources it contributes
src/light/%.o: ../src/light/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/managers/shaders/camera_position.cpp \
../src/managers/shaders/init.cpp \
../src/managers/shaders/main.cpp \
../src/managers/shaders/render_matrices.cpp \
../src/managers/shaders/shadow_framebuffer.cpp 

OBJS += \
./src/managers/shaders/camera_position.o \
./src/managers/shaders/init.o \
./src/managers/shaders/main.o \
./src/managers/shaders/render_matrices.o \
./src/managers/shaders/shadow_framebuffer.o 

CPP_DEPS += \
./src/managers/shaders/camera_position.d \
./src/managers/shaders/init.d \
./src/managers/shaders/main.d \
./src/managers/shaders/render_matrices.d \
./src/managers/shaders/shadow_framebuffer.d 


# Each subdirectory must supply rules for building sources it contributes
src/managers/shaders/%.o: ../src/managers/shaders/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



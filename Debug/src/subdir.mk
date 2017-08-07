################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/camera.cpp \
../src/drawer.cpp \
../src/error.cpp \
../src/keyboard.cpp \
../src/loop.cpp \
../src/mouse.cpp \
../src/popup.cpp \
../src/reader.cpp \
../src/skybox.cpp \
../src/window.cpp 

OBJS += \
./src/camera.o \
./src/drawer.o \
./src/error.o \
./src/keyboard.o \
./src/loop.o \
./src/mouse.o \
./src/popup.o \
./src/reader.o \
./src/skybox.o \
./src/window.o 

CPP_DEPS += \
./src/camera.d \
./src/drawer.d \
./src/error.d \
./src/keyboard.d \
./src/loop.d \
./src/mouse.d \
./src/popup.d \
./src/reader.d \
./src/skybox.d \
./src/window.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -I"/home/gatperdut/dev/gl/workspace/ChatoGL/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



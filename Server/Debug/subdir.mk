################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ClientHandler.cpp \
../CommandManager.cpp \
../GameManager.cpp \
../JoinCommand.cpp \
../ListGamesCommand.cpp \
../Main.cpp \
../Server.cpp \
../StartCommand.cpp 

OBJS += \
./ClientHandler.o \
./CommandManager.o \
./GameManager.o \
./JoinCommand.o \
./ListGamesCommand.o \
./Main.o \
./Server.o \
./StartCommand.o 

CPP_DEPS += \
./ClientHandler.d \
./CommandManager.d \
./GameManager.d \
./JoinCommand.d \
./ListGamesCommand.d \
./Main.d \
./Server.d \
./StartCommand.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



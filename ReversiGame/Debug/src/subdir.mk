################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AI.cpp \
../src/Board.cpp \
../src/Cell.cpp \
../src/Game.cpp \
../src/HumanPlayer.cpp \
../src/Main.cpp 

O_SRCS += \
../src/AI.o \
../src/Board.o \
../src/Cell.o \
../src/Game.o \
../src/HumanPlayer.o \
../src/Main.o 

OBJS += \
./src/AI.o \
./src/Board.o \
./src/Cell.o \
./src/Game.o \
./src/HumanPlayer.o \
./src/Main.o 

CPP_DEPS += \
./src/AI.d \
./src/Board.d \
./src/Cell.d \
./src/Game.d \
./src/HumanPlayer.d \
./src/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/ReversiGame/lib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



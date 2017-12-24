################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AI.cpp \
../src/AiGame.cpp \
../src/Board.cpp \
../src/Cell.cpp \
../src/Client.cpp \
../src/ClientPlayer.cpp \
../src/ConsoleDisplay.cpp \
../src/HumanPlayer.cpp \
../src/Main.cpp \
../src/OpponentClientPlayer.cpp \
../src/RemoteGame.cpp \
../src/TwoClientsGame.cpp 

OBJS += \
./src/AI.o \
./src/AiGame.o \
./src/Board.o \
./src/Cell.o \
./src/Client.o \
./src/ClientPlayer.o \
./src/ConsoleDisplay.o \
./src/HumanPlayer.o \
./src/Main.o \
./src/OpponentClientPlayer.o \
./src/RemoteGame.o \
./src/TwoClientsGame.o 

CPP_DEPS += \
./src/AI.d \
./src/AiGame.d \
./src/Board.d \
./src/Cell.d \
./src/Client.d \
./src/ClientPlayer.d \
./src/ConsoleDisplay.d \
./src/HumanPlayer.d \
./src/Main.d \
./src/OpponentClientPlayer.d \
./src/RemoteGame.d \
./src/TwoClientsGame.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/ReversiGame/include" -I"/home/adi/Reversi/ReversiGame/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



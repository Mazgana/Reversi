################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest-release-1.8.0/googletest/src/gtest-all.cc \
../googletest-release-1.8.0/googletest/src/gtest-death-test.cc \
../googletest-release-1.8.0/googletest/src/gtest-filepath.cc \
../googletest-release-1.8.0/googletest/src/gtest-port.cc \
../googletest-release-1.8.0/googletest/src/gtest-printers.cc \
../googletest-release-1.8.0/googletest/src/gtest-test-part.cc \
../googletest-release-1.8.0/googletest/src/gtest-typed-test.cc \
../googletest-release-1.8.0/googletest/src/gtest.cc \
../googletest-release-1.8.0/googletest/src/gtest_main.cc 

CC_DEPS += \
./googletest-release-1.8.0/googletest/src/gtest-all.d \
./googletest-release-1.8.0/googletest/src/gtest-death-test.d \
./googletest-release-1.8.0/googletest/src/gtest-filepath.d \
./googletest-release-1.8.0/googletest/src/gtest-port.d \
./googletest-release-1.8.0/googletest/src/gtest-printers.d \
./googletest-release-1.8.0/googletest/src/gtest-test-part.d \
./googletest-release-1.8.0/googletest/src/gtest-typed-test.d \
./googletest-release-1.8.0/googletest/src/gtest.d \
./googletest-release-1.8.0/googletest/src/gtest_main.d 

OBJS += \
./googletest-release-1.8.0/googletest/src/gtest-all.o \
./googletest-release-1.8.0/googletest/src/gtest-death-test.o \
./googletest-release-1.8.0/googletest/src/gtest-filepath.o \
./googletest-release-1.8.0/googletest/src/gtest-port.o \
./googletest-release-1.8.0/googletest/src/gtest-printers.o \
./googletest-release-1.8.0/googletest/src/gtest-test-part.o \
./googletest-release-1.8.0/googletest/src/gtest-typed-test.o \
./googletest-release-1.8.0/googletest/src/gtest.o \
./googletest-release-1.8.0/googletest/src/gtest_main.o 


# Each subdirectory must supply rules for building sources it contributes
googletest-release-1.8.0/googletest/src/%.o: ../googletest-release-1.8.0/googletest/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/ReversiGame/include" -I"/home/adi/Reversi/ReversiGame/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



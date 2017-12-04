################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest-release-1.8.0/googlemock/src/gmock-all.cc \
../googletest-release-1.8.0/googlemock/src/gmock-cardinalities.cc \
../googletest-release-1.8.0/googlemock/src/gmock-internal-utils.cc \
../googletest-release-1.8.0/googlemock/src/gmock-matchers.cc \
../googletest-release-1.8.0/googlemock/src/gmock-spec-builders.cc \
../googletest-release-1.8.0/googlemock/src/gmock.cc \
../googletest-release-1.8.0/googlemock/src/gmock_main.cc 

CC_DEPS += \
./googletest-release-1.8.0/googlemock/src/gmock-all.d \
./googletest-release-1.8.0/googlemock/src/gmock-cardinalities.d \
./googletest-release-1.8.0/googlemock/src/gmock-internal-utils.d \
./googletest-release-1.8.0/googlemock/src/gmock-matchers.d \
./googletest-release-1.8.0/googlemock/src/gmock-spec-builders.d \
./googletest-release-1.8.0/googlemock/src/gmock.d \
./googletest-release-1.8.0/googlemock/src/gmock_main.d 

OBJS += \
./googletest-release-1.8.0/googlemock/src/gmock-all.o \
./googletest-release-1.8.0/googlemock/src/gmock-cardinalities.o \
./googletest-release-1.8.0/googlemock/src/gmock-internal-utils.o \
./googletest-release-1.8.0/googlemock/src/gmock-matchers.o \
./googletest-release-1.8.0/googlemock/src/gmock-spec-builders.o \
./googletest-release-1.8.0/googlemock/src/gmock.o \
./googletest-release-1.8.0/googlemock/src/gmock_main.o 


# Each subdirectory must supply rules for building sources it contributes
googletest-release-1.8.0/googlemock/src/%.o: ../googletest-release-1.8.0/googlemock/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/ReversiGame/include" -I"/home/adi/Reversi/ReversiGame/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



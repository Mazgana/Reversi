################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest-release-1.8.0/googletest/samples/sample1.cc \
../googletest-release-1.8.0/googletest/samples/sample10_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample1_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample2.cc \
../googletest-release-1.8.0/googletest/samples/sample2_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample3_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample4.cc \
../googletest-release-1.8.0/googletest/samples/sample4_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample5_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample6_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample7_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample8_unittest.cc \
../googletest-release-1.8.0/googletest/samples/sample9_unittest.cc 

CC_DEPS += \
./googletest-release-1.8.0/googletest/samples/sample1.d \
./googletest-release-1.8.0/googletest/samples/sample10_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample1_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample2.d \
./googletest-release-1.8.0/googletest/samples/sample2_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample3_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample4.d \
./googletest-release-1.8.0/googletest/samples/sample4_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample5_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample6_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample7_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample8_unittest.d \
./googletest-release-1.8.0/googletest/samples/sample9_unittest.d 

OBJS += \
./googletest-release-1.8.0/googletest/samples/sample1.o \
./googletest-release-1.8.0/googletest/samples/sample10_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample1_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample2.o \
./googletest-release-1.8.0/googletest/samples/sample2_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample3_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample4.o \
./googletest-release-1.8.0/googletest/samples/sample4_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample5_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample6_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample7_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample8_unittest.o \
./googletest-release-1.8.0/googletest/samples/sample9_unittest.o 


# Each subdirectory must supply rules for building sources it contributes
googletest-release-1.8.0/googletest/samples/%.o: ../googletest-release-1.8.0/googletest/samples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/Game/include" -I"/home/adi/Reversi/Game/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



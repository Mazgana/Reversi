################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest-release-1.8.0/googletest/codegear/gtest_all.cc \
../googletest-release-1.8.0/googletest/codegear/gtest_link.cc 

CC_DEPS += \
./googletest-release-1.8.0/googletest/codegear/gtest_all.d \
./googletest-release-1.8.0/googletest/codegear/gtest_link.d 

OBJS += \
./googletest-release-1.8.0/googletest/codegear/gtest_all.o \
./googletest-release-1.8.0/googletest/codegear/gtest_link.o 


# Each subdirectory must supply rules for building sources it contributes
googletest-release-1.8.0/googletest/codegear/%.o: ../googletest-release-1.8.0/googletest/codegear/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/Game/include" -I"/home/adi/Reversi/Game/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



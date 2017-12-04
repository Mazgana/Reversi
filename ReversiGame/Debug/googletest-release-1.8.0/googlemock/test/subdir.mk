################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest-release-1.8.0/googlemock/test/gmock-actions_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-cardinalities_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-generated-actions_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-generated-function-mockers_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-generated-internal-utils_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-generated-matchers_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-internal-utils_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-matchers_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-more-actions_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-nice-strict_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-port_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock-spec-builders_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock_all_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock_ex_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock_leak_test_.cc \
../googletest-release-1.8.0/googlemock/test/gmock_link2_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock_link_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock_output_test_.cc \
../googletest-release-1.8.0/googlemock/test/gmock_stress_test.cc \
../googletest-release-1.8.0/googlemock/test/gmock_test.cc 

CC_DEPS += \
./googletest-release-1.8.0/googlemock/test/gmock-actions_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-cardinalities_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-generated-actions_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-generated-function-mockers_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-generated-internal-utils_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-generated-matchers_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-internal-utils_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-matchers_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-more-actions_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-nice-strict_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-port_test.d \
./googletest-release-1.8.0/googlemock/test/gmock-spec-builders_test.d \
./googletest-release-1.8.0/googlemock/test/gmock_all_test.d \
./googletest-release-1.8.0/googlemock/test/gmock_ex_test.d \
./googletest-release-1.8.0/googlemock/test/gmock_leak_test_.d \
./googletest-release-1.8.0/googlemock/test/gmock_link2_test.d \
./googletest-release-1.8.0/googlemock/test/gmock_link_test.d \
./googletest-release-1.8.0/googlemock/test/gmock_output_test_.d \
./googletest-release-1.8.0/googlemock/test/gmock_stress_test.d \
./googletest-release-1.8.0/googlemock/test/gmock_test.d 

OBJS += \
./googletest-release-1.8.0/googlemock/test/gmock-actions_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-cardinalities_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-generated-actions_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-generated-function-mockers_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-generated-internal-utils_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-generated-matchers_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-internal-utils_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-matchers_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-more-actions_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-nice-strict_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-port_test.o \
./googletest-release-1.8.0/googlemock/test/gmock-spec-builders_test.o \
./googletest-release-1.8.0/googlemock/test/gmock_all_test.o \
./googletest-release-1.8.0/googlemock/test/gmock_ex_test.o \
./googletest-release-1.8.0/googlemock/test/gmock_leak_test_.o \
./googletest-release-1.8.0/googlemock/test/gmock_link2_test.o \
./googletest-release-1.8.0/googlemock/test/gmock_link_test.o \
./googletest-release-1.8.0/googlemock/test/gmock_output_test_.o \
./googletest-release-1.8.0/googlemock/test/gmock_stress_test.o \
./googletest-release-1.8.0/googlemock/test/gmock_test.o 


# Each subdirectory must supply rules for building sources it contributes
googletest-release-1.8.0/googlemock/test/%.o: ../googletest-release-1.8.0/googlemock/test/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/ReversiGame/include" -I"/home/adi/Reversi/ReversiGame/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



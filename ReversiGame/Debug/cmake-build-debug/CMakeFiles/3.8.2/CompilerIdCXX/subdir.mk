################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cmake-build-debug/CMakeFiles/3.8.2/CompilerIdCXX/CMakeCXXCompilerId.cpp 

OBJS += \
./cmake-build-debug/CMakeFiles/3.8.2/CompilerIdCXX/CMakeCXXCompilerId.o 

CPP_DEPS += \
./cmake-build-debug/CMakeFiles/3.8.2/CompilerIdCXX/CMakeCXXCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
cmake-build-debug/CMakeFiles/3.8.2/CompilerIdCXX/%.o: ../cmake-build-debug/CMakeFiles/3.8.2/CompilerIdCXX/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/adi/Reversi/ReversiGame/include" -I"/home/adi/Reversi/ReversiGame/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



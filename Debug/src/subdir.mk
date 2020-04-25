################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IndexOutOfBoundException.cpp \
../src/unit_test.cpp 

OBJS += \
./src/IndexOutOfBoundException.o \
./src/unit_test.o 

CPP_DEPS += \
./src/IndexOutOfBoundException.d \
./src/unit_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/vibhath/lseg/gtest/googletest/googletest/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



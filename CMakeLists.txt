cmake_minimum_required(VERSION 3.6)
project(CardServiceSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_SOURCE_DIR})

if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCE_FILES Card/Card.h Card/Card.cpp Microservices/BankService.h Microservices/BankService.cpp
        Microservices/HealthInsuranceService.h Microservices/HealthInsuranceService.cpp
        Microservices/PassportOfficeService.h Microservices/PassportOfficeService.cpp
        Microservices/ServiceFactory.h Microservices/ServiceFactory.cpp
        Terminal/Terminal.h Terminal/Terminal.cpp Utils/Date.h Utils/Date.cpp
        Utils/Passport.h Utils/Passport.cpp Utils/Policy.h Utils/Policy.cpp)

add_library(CardServiceSystemLib ${SOURCE_FILES})

if(WITH_TEST)
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    set(TEST Test/tests.h)
    add_executable(CardServiceSystem main.cpp ${TEST})
    target_link_libraries(CardServiceSystem CardServiceSystemLib ${GTEST_LIBRARIES} pthread)
endif()

find_package(Doxygen REQUIRED)

set(DOXYGEN_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

configure_file(${DOXYGEN_INPUT} ${DOXYGEN_OUTPUT} @ONLY)

add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUTPUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)


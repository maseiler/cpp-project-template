cmake_minimum_required(VERSION 3.20)

project(cpp-template VERSION 2024.1
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/maseiler/cpp-template")


#####################################################################
# Dependencies
#####################################################################

include(FetchContent)

# Boost
###################################
find_package(Boost REQUIRED)

# Google Test
###################################
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_GetProperties(googletest)
if (NOT catch_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR}
            EXCLUDE_FROM_ALL)
endif ()

add_executable(${PROJECT_NAME}-tests
        tests/MyClassTest.cpp)

target_link_libraries(${PROJECT_NAME}-tests
        PRIVATE gtest_main ${PROJECT_NAME}::${PROJECT_NAME})

# Google Benchmark
###################################
set(BENCHMARK_ENABLE_TESTING off)
FetchContent_Declare(
        googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.8.3)

FetchContent_MakeAvailable(googlebenchmark)

add_executable(${PROJECT_NAME}-benchmarks
        benchmarks/MyClassBenchmark.cpp)

target_link_libraries(${PROJECT_NAME}-benchmarks
        PRIVATE benchmark::benchmark ${PROJECT_NAME}::${PROJECT_NAME})


#####################################################################
# Libraries
#####################################################################

add_library(${PROJECT_NAME}
        src/MyLib/MyClass.cpp)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION})

target_include_directories(${PROJECT_NAME}
        PUBLIC include
        PRIVATE src)

target_link_libraries(${PROJECT_NAME}
        PRIVATE Boost::boost)


#####################################################################
# Compiler options
#####################################################################

target_compile_options(${PROJECT_NAME}
        PRIVATE -Wall -Wextra -pedantic -Werror)

target_compile_options(${PROJECT_NAME}-tests
        PRIVATE -Wall -Wextra -pedantic -Werror)

target_compile_features(${PROJECT_NAME}
        PRIVATE cxx_std_17)

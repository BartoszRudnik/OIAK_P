cmake_minimum_required(VERSION 3.16)
project(OIAK_P)

set(CMAKE_CXX_STANDARD 20)

add_executable(OIAK_P main.cpp QuickSort.cpp QuickSort.h QuickSortParallel.cpp QuickSortParrallel.h BucketSort.cpp QuickSortOptimal.cpp QuickSortOptimal.h testy.cpp testy.h BubbleSort.cpp BubbleSort.h BubbleSortParallel.cpp BubbleSortParallel.h)

find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} Threads::Threads)
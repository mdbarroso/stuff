cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON) 
find_package(Boost 1.45.0 COMPONENTS regex) 

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests DataTypesTest.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread ${Boost_LIBRARIES})

#add_executable(runWordCountTests WordCountTests.cpp)
#target_link_libraries(runWordCountTests ${GTEST_LIBRARIES} pthread ${Boost_LIBRARIES})

add_executable(wordCount WordCount.cpp DataTypes.cpp)
target_link_libraries(wordCount ${GTEST_LIBRARIES} pthread ${Boost_LIBRARIES})

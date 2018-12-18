cmake_minimum_required(VERSION 2.8.3)
project(preprocessor)

SET(CMAKE_BUILD_TYPE "Release")

## Compile as C++11
#add_compile_options(-std=c++11) # failed to work on ubuntu 14.04 (TLS error)

## append external lib
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

## find PCL
find_package(PCL REQUIRED)
include_directories (${PCL_INCLUDE_DIRS})

## find opencv
find_package(OpenCV REQUIRED)

## find CUDA
find_package(CUDA)
include_directories (${CUDA_INCLUDE_DIRS})

## find Python
find_package(Python REQUIRED)
include_directories (${PYTHON_INCLUDE_DIRS})

## find Numpy
find_package(Numpy REQUIRED)
include_directories (${PYTHON_NUMPY_INCLUDE_DIR})

include_directories(include)


add_library(${PROJECT_NAME} SHARED
        #src/test1.cpp
        #src/test_class.cpp
        #src/test_constructor.cpp
        #src/test_class_data_member.cpp
        #src/test_class_attributes.cpp
        src/test_class_inherit.cpp
        )

# set prefix otherwise the output will be libfoo.so instead of foo.so
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

target_link_libraries(${PROJECT_NAME}
        boost_python ${BOOST_LIBRARIES} ${PYTHON_LIBARIES}
        ${PCL_LIBRARIES} ${OpenCV_LIBS})


##test

#add_executable(test_loader test/test_loader.cpp)
#target_link_libraries(test_loader ${PROJECT_NAME} )
#
#add_executable(test_tighter test/test_tighter.cpp)
#target_link_libraries(test_tighter ${PROJECT_NAME} )
#
#add_executable(test_augmentor test/test_augmentor.cpp)
#target_link_libraries(test_augmentor ${PROJECT_NAME} )
#
#add_executable(test_instance_label test/test_instance_label.cpp)
#target_link_libraries(test_instance_label ${PROJECT_NAME} )




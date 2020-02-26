cmake_minimum_required(VERSION 2.8)
project(test_useEigen_useCUDA)


#// cmake寻找cuda，并且CUDA_ADD_EXECUTABLE等cuda前缀的命令是由cuda提供的，cmake本身不支持
find_package(CUDA REQUIRED)
include_directories(${CUDA_INCLUDE_DIRS})
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -gencode=arch=compute_61,code=sm_61")



#// C++和CUDA的编译参数，可选。如果CMAKE_CXX_FLAGS和CUDA_NVCC_FLAGS有相同参数会报错
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -g -G")


#include_directories("/usr/include/eigen3")
#find_package(Eigen3 REQUIRED)

set(EIGEN_ROOT "/data/surfelwarp/external/eigen3.4")
set(EIGEN_INCLUDE_DIR ${EIGEN_ROOT})
INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIR})



find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})

# The boost library is contained in pcl
find_package(Boost REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})





add_library(useEigen useEigen.cpp)
#// 注意cmake调用nvcc进行编译
CUDA_ADD_LIBRARY(useCUDA useCUDA.cu)



add_executable(main main.cpp)
target_link_libraries(main useCUDA useEigen)


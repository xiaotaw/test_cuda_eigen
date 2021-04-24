cmake_minimum_required(VERSION 2.8)
project(test_useEigen_useCUDA)


#// cmake寻找cuda，并且CUDA_ADD_EXECUTABLE等cuda前缀的命令是由cuda提供的，cmake本身不支持
find_package(CUDA REQUIRED)
include_directories(${CUDA_INCLUDE_DIRS})
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -gencode=arch=compute_61,code=sm_61")
#set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} --expt-relaxed-constexpr")
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -Xcudafe --diag_suppress=esa_on_defaulted_function_ignored")

#// C++和CUDA的编译参数，可选。如果CMAKE_CXX_FLAGS和CUDA_NVCC_FLAGS有相同参数会报错
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -g -G")

# system eigen3 is not compatible with CUDA10.0, using Eigen-3.3.9 instead
#set(Eigen3_DIR "/home/xt/Documents/data/Others/eigen-3.3.9/install/share/eigen3/cmake")
find_package(Eigen3 REQUIRED)
if(EIGEN3_FOUND)
  message(STATUS "Found Eigen ${EIGEN3_VERSION_STRING} at ${EIGEN3_INCLUDE_DIR}")
  if(EIGEN3_VERSION_STRING VERSION_LESS 3.3.9) 
    message(FATAL_ERROR "CUDA requires Eigen version >=3.3.9, please specify custom eigen by setting Eigen3_DIR") 
  else()
    message(STATUS "EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR}")
    INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})
  endif()
endif()

set(PCL_DIR "/home/xt/Documents/data/Others/pcl_1.11.1/install/share/pcl-1.11")
find_package(PCL REQUIRED)
message(STATUS "PCL_INCLUDE_DIRS: ${PCL_INCLUDE_DIRS}")
include_directories(${PCL_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS
    velodyne_pointcloud
)
include_directories(${catkin_INCLUDE_DIRS})

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


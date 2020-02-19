#include <iostream>
#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>


int test_eigen() {

  Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Random();      // 随机数矩阵
  std::cout << "random matrix: \n" << matrix_33 << std::endl;
  std::cout << "trace: " << matrix_33.trace() << std::endl;          // 迹

  return 0;
}

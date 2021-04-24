# test_cuda_eigen
test compatibility between cuda and eigen, for more info, please refer to issue https://github.com/weigao95/surfelwarp/issues/30

| ubuntu | Eigen | cuda | status |
| ---    | ---   | ---  | ---    |
| 18.04  | 3.3.4 | 9.0.176 | bad |
| 18.04  | 3.3.90| 9.0.176 | good |
| 18.04  | 3.3.4 | 10.0.130 | bad |
| 18.04  | 3.3.9| 10.0.130 | good |

## dependency
Eigen=3.3.9, please refer to: [https://github.com/xiaotaw/Notes/ubuntu/coding.md]

## compile

```bash
mkdir build && cd build
cmake .. -DEigen3_DIR=/home/xt/Documents/data/Others/eigen-3.3.9/install/share/eigen3/cmake
make -j
```


## Eigen vesion

Eigen version check via `Macros.h` in eigen dir, e.g.
```bash
grep -nR VERSION /usr/include/eigen3/Eigen/src/Core/util/Macros.h
```
```vim
14:#define EIGEN_WORLD_VERSION 3
15:#define EIGEN_MAJOR_VERSION 3
16:#define EIGEN_MINOR_VERSION 4
```

Eigen-3.3.4: installed by `sudo apt-get install libeigen3-dev`
Eigen-3.3.90: comes from [https://github.com/weigao95/surfelwarp/tree/master/external/eigen3.4]
Eigen-3.3.9: comes from [https://gitlab.com/libeigen/eigen/-/archive/3.3.9/eigen-3.3.9.tar.gz] 


## CUDA version

CUDA version check via `nvcc --version` if cuda bin has been added to your env PATH

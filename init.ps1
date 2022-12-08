# Initialize the project with the following CMake configurations

Write-Output ""
Write-Output "cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G Ninja -S .\ -B ./cmake-build-debug"
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G Ninja -S ./ -B ./cmake-build-debug

Write-Output ""
Write-Output "cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G Ninja -S .\ -B ./cmake-build-release"
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G Ninja -S ./ -B ./cmake-build-release

Write-Output ""
Write-Output "cmake -DCMAKE_BUILD_TYPE=MinSizeRel -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G Ninja -S .\ -B ./cmake-build-release"
cmake -DCMAKE_BUILD_TYPE=MinSizeRel -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -G Ninja -S ./ -B ./cmake-build-release

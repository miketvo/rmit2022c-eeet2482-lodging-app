# EEET2482/COSC2082 ASSIGNMENT
VACATION HOUSE EXCHANGE APPLICATION


## About

This is an assignment project for EEET2482 Software Engineering Design / COSC2082 Advanced Programming Techniques offered at RMIT University Vietnam during Semester 2022C.

> Assume that you are involved in a start-up who came up with an idea to make an app for people to exchange their houses on vacation. The app will allow registered members to use houses of other members when they go on vacation...
[Read more](ProjectDetails.md)

This project uses [C++14](https://en.wikipedia.org/wiki/C%2B%2B14).


## Project Structure

```
.
├── .github/
├── src/
├── test/
├── CMakeLists.txt
├── .clang-format
├── .gitignore
├── init.ps1
├── init.sh
├── build.ps1
├── build.sh
├── ProjectScheme.xml
├── ProjectRequirements.md
├── LICENSE
└── README.md
```

1. `.github/`: This directory contains GitHub repository configurations.
2. `src/`: This directory contains all C++ source code for this project.
3. `test/`: This directory contains all CTest source files.
4. `CMakeLists.txt`: This file contains build and test configurations for CMake and CTest.
5. `.clang-format`: This YAML-formatted file defines C/C++ code style for this project.
6. `.gitignore`: This file tells git which files it should not track / not maintain a version history for.
7. `init.sh`: This Shell script initializes CMake and build folders for this project.
8. `init.ps1`: This Windows Powershell script initializes CMake and build folders for this project.
9. `build.sh`: This Shell script is a wrapper for CMake build processes.
10. `build.ps1`: This Windows Powershell script is a wrapper for CMake build processes.
11. `ProjectScheme.xml`: JetBrains XML code style file that contains C./C++ formatting rules. Alternative to `.clang-format`.
12. `ProjectRequirements.md`: Project requirements provided by the course EEET2482/COSC2082.
13. `LICENSE`: MIT
14. `README.md`: A text file containing useful reference information about this project.


## Quick start

### Prerequisites
| Name   | Recommended version | Notes    |
|--------|---------------------|----------|
| g++    | 9.3.0 or higher     |          |
| cmake  | 3.10.0 or higher    |          |
| ninja  | 1.10.0 or higher    |          |
| clangd | 10.0.0 or higher    | Optional |

### Setting up development environment

1. Clone this repository using git: 
    * HTTPS
      ```shell
      git clone https://github.com/miketvo/rmit2022c-eeet2482-lodging-app.git
      ```

    * SSH
      ```shell
      git clone git@github.com:miketvo/rmit2022c-eeet2482-lodging-app.git
      ```
    
    Alternatively, you can download this repository as a ZIP file and extract it (not recommended for development purposes since git features are not enabled for this method).
2. Initialize CMake and build folders:
    * Linux/MacOS
      ```shell
      ./init.sh
      ```

    * Windows
      ```shell
      ./init.ps1
      ```

   This will generate three build folders corresponding to three respective build modes offered in this project:
    * `cmake-build-debug/`
    * `cmake-build-release/`
    * `cmake-build-minsizerel/`

### Building

* Linux/MacOS
  ```shell
  ./build.sh [Options] -m <build-mode> 
  ```

* Windows
  ```shell
  ./build.ps1 [Options] -m <build-mode> 
  ```

For all available options flags and build modes, use:

* Linux/MacOS
  ```shell
  ./build.sh -h
  ```

* Windows
  ```shell
  ./build.ps1 -h
  ```

### Testing

1. Navigate to one of the build folders:
    ```
    cd cmake-build-<debug|release|minsizerel>
    ```
2. Run CTest (bundled with CMake):
    ```shell
    ctest
    ```

To run tests selectively, use the `-R`/`--tests-regex` or `-N`/`--show-only` flag. Refer to [CTest Documentation](https://cmake.org/cmake/help/latest/manual/ctest.1.html).

To write and add test configurations, please refer to [Testing With CMake and CTest](https://cmake.org/cmake/help/book/mastering-cmake/chapter/Testing%20With%20CMake%20and%20CTest.html). **Note: All test source files for this project are placed under `test/`.**

#!/bin/bash
#
# Syntax: build.sh -build.sh [Options] -m <build-mode>
# Options:
#   -m Specify build mode. Accepted values are
#       'debug', 'debug-test',
#       'release', 'release-test',
#       'minsizerel', and 'minsizerel-test'
#   -c (Optional) Clean built files. Use in conjunction with '-m' to clean built files in a specific build folder.
#   -h (Optional) Display help and exit.
#

clean=0
has_mode=0
while getopts m:hc flag; do
  case "$flag" in
  m)
    mode=${OPTARG}
    has_mode=1
    ;;
  h)
    echo "Syntax: build.sh [Options] -m <build-mode>"
    echo "Options:"
    echo "  -m Specify build mode. Accepted values are"
    echo "      'debug', 'debug-test',"
    echo "      'release', 'release-test',"
    echo "      'minsizerel', and 'minsizerel-test'"
    echo "  -c (Optional) Clean built files. Use in conjunction with '-m' to clean built files in a specific build folder."
    echo "  -h (Optional) Display this help and exit."
    exit 0
    ;;
  c) clean=1 ;;
  *)
    echo "Try 'build.sh -h' for more information."
    exit 1
    ;;
  esac
done

if [ $clean -eq 1 ] && [ $has_mode -eq 0 ]; then
  echo "[ Clean | All ]"

  echo "cmake --build ./cmake-build-debug --target clean -j 9"
  cmake --build ./cmake-build-debug --target clean -j 9
  echo "cmake --build ./cmake-build-release --target clean -j 9"
  cmake --build ./cmake-build-release --target clean -j 9
  echo "cmake --build ./cmake-build-minsizerel --target clean -j 9"
  cmake --build ./cmake-build-minsizerel --target clean -j 9

  exit 0;
fi

if [ "" = "${mode}" ]; then
  echo "Error: No build mode specified. Try 'build.sh -h' for more information."
  exit 1
fi


case "$mode" in
"debug")
  if [ "${clean}" -eq 1 ]; then
    echo "[ Clean | Debug ]"
    echo "cmake --build ./cmake-build-debug --target clean -j 9"
    cmake --build ./cmake-build-debug --target clean -j 9
    echo "[ Clean finished ]"
  else
    echo "[ Build | Debug ]"
    echo "cmake --build ./cmake-build-debug --target lodging -j 9"
    cmake --build ./cmake-build-debug --target lodging -j 9
    echo "[ Build finished ]"
  fi
  ;;
"debug-tests")
  if [ $clean -eq 1 ]; then
    echo "[ Clean | Debug ]"
    echo "cmake --build ./cmake-build-debug --target clean -j 9"
    cmake --build ./cmake-build-debug --target clean -j 9
    echo "[ Clean finished ]"
  else
    echo "[ Build | Debug ]"
    echo "cmake --build ./cmake-build-debug --target lodging all-tests -j 9"
    cmake --build ./cmake-build-debug --target lodging all-tests -j 9
    echo "[ Build finished ]"
  fi
  ;;
"release")
  if [ $clean -eq 1 ]; then
    echo "[ Clean | Release ]"
    echo "cmake --build ./cmake-build-release --target clean -j 9"
    cmake --build ./cmake-build-release --target clean -j 9
    echo "[ Clean finished ]"
  else
    echo "[ Build | Release ]"
    echo "cmake --build ./cmake-build-release --target lodging -j 9"
    cmake --build ./cmake-build-release --target lodging -j 9
    echo "[ Build finished ]"
  fi
  ;;
"release-tests")
  if [ $clean -eq 1 ]; then
    echo "[ Clean | Release ]"
    echo "cmake --build ./cmake-build-release --target clean -j 9"
    cmake --build ./cmake-build-release --target clean -j 9
    echo "[ Clean finished ]"
  else
    echo "[ Build | Release ]"
    echo "cmake --build ./cmake-build-release --target lodging all-tests -j 9"
    cmake --build ./cmake-build-release --target lodging all-tests -j 9
    echo "[ Build finished ]"
  fi
  ;;
"minsizerel")
  if [ $clean -eq 1 ]; then
    echo "[ Clean | Release ]"
    echo "cmake --build ./cmake-build-minsizerel --target clean -j 9"
    cmake --build ./cmake-build-minsizerel --target clean -j 9
    echo "[ Clean finished ]"
  else
    echo "[ Build | Release ]"
    echo "cmake --build ./cmake-build-minsizerel --target lodging -j 9"
    cmake --build ./cmake-build-minsizerel --target lodging -j 9
    echo "[ Build finished ]"
  fi
  ;;
"minsizerel-test")
  if [ $clean -eq 1 ]; then
    echo "[ Clean | Release ]"
    echo "cmake --build ./cmake-build-minsizerel --target clean -j 9"
    cmake --build ./cmake-build-minsizerel --target clean -j 9
    echo "[ Clean finished ]"
  else
    echo "[ Build | Release ]"
    echo "cmake --build ./cmake-build-minsizerel --target lodging all-tests -j 9"
    cmake --build ./cmake-build-minsizerel --target lodging all-tests -j 9
    echo "[ Build finished ]"
  fi
  ;;
*)
  echo "Invalid build mode '$mode'"
  exit 1
  ;;
esac

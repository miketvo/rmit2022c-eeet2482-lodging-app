#
# Syntax: build.ps1 [options] -m <build-mode>
#         build.ps1 -c
# Options:
#   -m Specify build mode. Accepted values are
#       'debug', 'debug-test',
#       'release', 'release-test',
#       'minsizerel', and 'minsizerel-test'
#   -c Clean built files. Use in conjunction with '-m' to clean built files in a specific build folder.
#   -h Display help and exit.
#

[CmdletBinding()] param(
    [string]$m,
    [switch]$c,
    [switch]$h
)

if ($h.IsPresent) {
    Write-Output "Syntax: build.ps1 [options] -m <build-mode>"
    Write-Output "        build.ps1 -c"
    Write-Output "Options:"
    Write-Output "  -m Specify build mode. Accepted values are"
    Write-Output "      'debug', 'debug-test',"
    Write-Output "      'release', 'release-test',"
    Write-Output "      'minsizerel', and 'minsizerel-test'"
    Write-Output "  -c Clean built files. Use in conjunction with '-m' to clean built files in a specific build folder."
    Write-Output "  -h Display this help and exit."
    exit 0
}

if ( $c.IsPresent -and (!$PSBoundParameters.ContainsKey('m')) ) {
    Write-Output "[ Clean | All ]"

    Write-Output "cmake --build ./cmake-build-debug --target clean -j 9"
    cmake --build ./cmake-build-debug --target clean -j 9
    Write-Output "cmake --build ./cmake-build-release --target clean -j 9"
    cmake --build ./cmake-build-release --target clean -j 9
    Write-Output "cmake --build ./cmake-build-minsizerel --target clean -j 9"
    cmake --build ./cmake-build-minsizerel --target clean -j 9

    exit 0
}

switch ($m) {
    "" {
        Write-Host "Error: No build mode specified. Try 'build.ps1 -h' for more information." -ForegroundColor Red
        exit 1
    }
    "debug" {
        if ($c.IsPresent)
        {
            Write-Output "[ Clean | Debug ]"
            Write-Output "cmake --build ./cmake-build-debug --target clean -j 9"
            cmake --build ./cmake-build-debug --target clean -j 9
            Write-Output "[ Clean finished ]"
        }
        else
        {
            Write-Output "[ Build | Debug ]"
            Write-Output "cmake --build ./cmake-build-debug --target lodging -j 9"
            cmake --build ./cmake-build-debug --target lodging -j 9
            Write-Output "[ Build finished ]"
        }
    }
    "debug-tests" {
        if ($c.IsPresent)
        {
            Write-Output "[ Clean | Debug ]"
            Write-Output "cmake --build ./cmake-build-debug --target clean -j 9"
            cmake --build ./cmake-build-debug --target clean -j 9
            Write-Output "[ Clean finished ]"
        }
        else
        {
            Write-Output "[ Build | Debug ]"
            Write-Output "cmake --build ./cmake-build-debug --target lodging all-tests -j 9"
            cmake --build ./cmake-build-debug --target lodging all-tests -j 9
            Write-Output "[ Build finished ]"
        }
    }
    "release" {
        if ($c.IsPresent)
        {
            Write-Output "[ Clean | Release ]"
            Write-Output "cmake --build ./cmake-build-release --target clean -j 9"
            cmake --build ./cmake-build-release --target clean -j 9
            Write-Output "[ Clean finished ]"
        }
        else
        {
            Write-Output "[ Build | Release ]"
            Write-Output "cmake --build ./cmake-build-release --target lodging -j 9"
            cmake --build ./cmake-build-release --target lodging -j 9
            Write-Output "[ Build finished ]"
        }
    }
    "release-tests" {
        if ($c.IsPresent)
        {
            Write-Output "[ Clean | Release ]"
            Write-Output "cmake --build ./cmake-build-release --target clean -j 9"
            cmake --build ./cmake-build-release --target clean -j 9
            Write-Output "[ Clean finished ]"
        }
        else
        {
            Write-Output "[ Build | Release ]"
            Write-Output "cmake --build ./cmake-build-release --target lodging all-tests -j 9"
            cmake --build ./cmake-build-release --target lodging all-tests -j 9
            Write-Output "[ Build finished ]"
        }
    }
    "minsizerel" {
        if ($c.IsPresent)
        {
            Write-Output "[ Clean | Release ]"
            Write-Output "cmake --build ./cmake-build-minsizerel --target clean -j 9"
            cmake --build ./cmake-build-minsizerel --target clean -j 9
            Write-Output "[ Clean finished ]"
        }
        else
        {
            Write-Output "[ Build | Release ]"
            Write-Output "cmake --build ./cmake-build-minsizerel --target lodging -j 9"
            cmake --build ./cmake-build-minsizerel --target lodging -j 9
            Write-Output "[ Build finished ]"
        }
    }
    "minsizerel-test" {
        if ($c.IsPresent)
        {
            Write-Output "[ Clean | Release ]"
            Write-Output "cmake --build ./cmake-build-minsizerel --target clean -j 9"
            cmake --build ./cmake-build-minsizerel --target clean -j 9
            Write-Output "[ Clean finished ]"
        }
        else
        {
            Write-Output "[ Build | Release ]"
            Write-Output "cmake --build ./cmake-build-minsizerel --target lodging all-tests -j 9"
            cmake --build ./cmake-build-minsizerel --target lodging all-tests -j 9
            Write-Output "[ Build finished ]"
        }
    }
    Default {
        Write-Host "Invalid build mode '$m'" -ForegroundColor Red
        exit 1
    }
}

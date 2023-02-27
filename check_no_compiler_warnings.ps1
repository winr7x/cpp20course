# Checked with PSScriptAnalyzer

# The script checks the entire project for compile warnings
# It invokes cmake configure and cmake build with the -DROOSTER_WARNINGS_AS_ERRORS=ON flag and exits with an error if there is any compile error

param ([ValidateRange(1,999)] [Int] $Jobs)

$ScriptName = $MyInvocation.MyCommand.Name

function Usage {
  Write-Output "Usage: $ScriptName -Jobs <job_count>"
}

if ($PSBoundParameters.Count -ne 1) {
  Usage
  Exit 1
}

function Write-Title {

  param (
    $Title
  )

  Write-Output ""
  Write-Output "#######################################################################################################"
  Write-Output "######### $Title"
  Write-Output "#######################################################################################################"
  Write-Output ""
}

function Rebuild {

  param (
    $Compiler,
    $ConfigureExitCode,
    $BuildExitCode,
    $Jobs
  )

  Write-Title $Compiler

  Remove-Item -ErrorAction Ignore -Recurse .\build\

  if ($Compiler -eq "CLANG") {
    cmake -DROOSTER_WARNINGS_AS_ERRORS=ON -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G 'MinGW Makefiles' -S .\ -B .\build\
  } elseif ($Compiler -eq "GCC") {
    cmake -DROOSTER_WARNINGS_AS_ERRORS=ON -G 'MinGW Makefiles' -S .\ -B .\build\
  } elseif ($Compiler -eq "MSVC") {
    cmake -G 'Visual Studio 17 2022' -S .\ -B .\build\
  } else {
    Write-Output "Unexpected compiler $Compiler"
    Exit 2
  }

  if(-Not $?) {
    Write-Output "Cmake configure $Compiler failed";
    Exit $ConfigureExitCode
  }

  cmake --build .\build\ --config Release --clean-first -j $Jobs

  if(-Not $?) {
    Write-Output "Cmake build $Compiler failed";
    Exit $BuildExitCode
  }
}

Rebuild -Compiler CLANG -ConfigureExitCode 3 -BuildExitCode 4 -Jobs $Jobs
Rebuild GCC -ConfigureExitCode 5 -BuildExitCode 6 -Jobs $Jobs
Rebuild MSVC -ConfigureExitCode 7 -BuildExitCode 8 -Jobs $Jobs

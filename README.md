# My study of the course [The C++20 Masterclass: From Fundamentals to Advanced](https://www.udemy.com/course/the-modern-cpp-20-masterclass/)

## Configure & build

### Configure MSVC
```powershell
# Install Visual Studio
# Launch Windows Start Menu --> Visual Studio 2022 --> 'Developer PowerShell for VS 2022'

# In PowerShell:
cd $Env:USERPROFILE\Documents\cpp20course\
cmake -G 'Visual Studio 17 2022' -S .\ -B .\build\                                                     # configure cmake msvc. way 1
& 'C:\Program Files\CMake\bin\cmake.exe' -G 'Visual Studio 17 2022' -S .\ -B .\build\                  # configure cmake msvc. way 2

# -G <generator-name> -- you can get generators list in 'cmake --help'
# & is the call operator which allows you to execute a command, a script, or a function
```

### Configure GCC/Clang
```powershell
# Install MinGW
# In PowerShell:
cd $Env:USERPROFILE\Documents\cpp20course\
cmake -G 'MinGW Makefiles' -S .\ -B .\build\                                                           # configure cmake gcc
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G 'MinGW Makefiles' -S .\ -B .\build\     # configure cmake clang
```

### Build
```powershell
# In PowerShell:
cd $Env:USERPROFILE\Documents\cpp20course\
cmake --build .\build\ --config Release --clean-first --target 5.6.RelationalOperators #--verbose      # build specific target
cmake --build .\build\ --config Release --verbose --clean-first -j1                                    # build entire project
```

## Tags

In cpp files tags are placed:

`NEW_FOR_ME` - Information which was new for me.  
`UNCOMMENT_TO_SEE` - Uncomment code marked with this tag to get error or warning or something else.

To search tag in project:

```powershell
# In PowerShell:
dir -Recurse | sls -pattern "NEW_FOR_ME"
```

## clang-format

To format all cpp files in project:

```powershell
# In PowerShell:
cd $Env:USERPROFILE\Documents\cpp20course\
clang-format -i @(Get-ChildItem -Filter *.cpp  -Recurse | Where {$_.FullName -notlike "*\build\*"} | % { $_.FullName })
```

## Check project is warnings-free
```powershell
# In PowerShell:
.\check_no_compiler_warnings.ps1 -Jobs 8

# To check PowerShell script for drawbacks:
Install-Module PSScriptAnalyzer -Force -Scope CurrentUser
Invoke-ScriptAnalyzer check_no_compiler_warnings.ps1
```

## How to launch VSCode in Windows
```
Win + Pause --> Advanced system settings --> Add to User's PATH var value '%USERPROFILE%\AppData\Local\Programs\Microsoft VS Code\bin'
Visual Studio 2022 --> Continue without code --> Tools --> Options --> Projects and Solutions --> Locations --> Project location --> set "C:\cpp20course\"
Pin to taskbar "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2022\Visual Studio Tools\Developer PowerShell for VS 2022.lnk" 
Launch Developer PowerShell, enter 'code .'
```
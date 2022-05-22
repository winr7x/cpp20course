## How to configure and build project

### Configure with MSVC
```powershell
# Windows Start Menu --> Visual Studio 2022 --> 'Developer PowerShell for VS 2022'

cd $Env:USERPROFILE\Documents\cpp31hours\
cmake -G 'Visual Studio 17 2022' -S .\ -B .\build\                                                     # configure cmake msvc. way 1
& 'C:\Program Files\CMake\bin\cmake.exe' -G 'Visual Studio 17 2022' -S .\ -B .\build\                  # configure cmake msvc. way 2

# -G <generator-name> -- you can get generators list in 'cmake --help'
# & is the call operator which allows you to execute a command, a script, or a function
```

### Configure with GCC or Clang
```powershell
# In Windows:
cd $Env:USERPROFILE\Documents\cpp31hours\
cmake -G 'MinGW Makefiles' -S .\ -B .\build\                                                           # configure cmake gcc
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G 'MinGW Makefiles' -S .\ -B .\build\     # configure cmake clang
```

```bash
# In Linux:
# todo
```

### Build
```powershell
# In Windows:
cd $Env:USERPROFILE\Documents\cpp31hours\
cmake --build .\build\ --config Release --clean-first --target 5.6.RelationalOperators #--verbose      # build specific target
cmake --build .\build\ --config Release --verbose --clean-first                                        # build entire project
```

```
# In Linux:
# todo
```

## Tags

`NEW_FOR_ME` - Information which was new for me.  
`UNCOMMENT_FOR_ERROR` - Uncomment code marked with this tag to get error or warning.

To search tag in project:

```powershell
# In PowerShell:
dir -Recurse | sls -pattern "NEW_FOR_ME"
```

## clang-format

To format all cpp files in project:

```powershell
# In Windows:
cd $Env:USERPROFILE\Documents\cpp31hours\
clang-format -i @(Get-ChildItem -Filter *.cpp  -Recurse | Where {$_.FullName -notlike "*\build\*"} | % { $_.FullName })
```

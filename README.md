## How to configure and build project

### Configure with MSVC
```powershell
# Windows Start Menu --> Visual Studio 2022 --> 'Developer PowerShell for VS 2022'

& 'C:\Program Files\CMake\bin\cmake.exe' -G 'Visual Studio 17 2022' -S .\ -B .\build\                                                     # configure cmake msvc

# -G <generator-name> -- you can get generators list in 'cmake --help'
```

### Configure with GCC or Clang
```powershell
& 'C:\Program Files\CMake\bin\cmake.exe' -G 'MinGW Makefiles' -S .\ -B .\build\                                                           # configure cmake gcc
& 'C:\Program Files\CMake\bin\cmake.exe' -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G 'MinGW Makefiles' -S .\ -B .\build\     # configure cmake clang
```

### Build
```powershell
 & 'C:\Program Files\CMake\bin\cmake.exe' --build .\build\ --config Release --verbose --clean-first                                       # build entire project
```

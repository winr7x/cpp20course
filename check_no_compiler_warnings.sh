#!/bin/bash

# The script checks the entire project for compile warnings
# It invokes cmake configure and cmake build with the -DROOSTER_WARNINGS_AS_ERRORS=ON flag and exits with an error if there is any compile error

cmake -DROOSTER_WARNINGS_AS_ERRORS=ON -S . -B build
cmake --build build --config Release --clean-first

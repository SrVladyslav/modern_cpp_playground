# data_structures

C++20 project compiled with GCC (`g++`).

## Using `make` (main.cpp)

```
make          # optimized build (-O2) -> main.exe
make debug    # debug build (-O0 -g) -> main_debug.exe
make run      # build (if needed) and run main.exe
make clean    # remove built executables
```

## Compiling a specific .cpp file manually

Useful for one-off files (e.g. things under `base_to_remember/`) that aren't wired into the Makefile.

Basic compile:
```
g++ -std=c++20 -Wall -Wextra -o <output_name> <path/to/file>.cpp
```

Optimized (release-style):
```
g++ -std=c++20 -Wall -Wextra -O2 -o <output_name> <path/to/file>.cpp
```

Debug build (no optimization, debug symbols):
```
g++ -std=c++20 -Wall -Wextra -O0 -g -o <output_name> <path/to/file>.cpp
```

Example:
```
g++ -std=c++20 -Wall -Wextra -O2 -o inCellClass base_to_remember/inCellClass.cpp
```

## Running the executable (Windows)

```
./<output_name>.exe
```

Note: in this environment, running a freshly built `.exe` directly from Git Bash can occasionally fail (segfault or "not recognized"). If that happens, run it from PowerShell instead:
```
.\<output_name>.exe
```

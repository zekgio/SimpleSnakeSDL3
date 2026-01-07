# Snake (C++ / SDL3)

A minimal version of the classic snake game written in modern C++ using SDL3 for rendering.

![Animazione](https://github.com/user-attachments/assets/967f0197-2da4-4a6c-a185-63a0377128b3)

## Features
- **C++20 Standard**
- **SDL3** for graphics and input handling.
- **CMake FetchContent**: Automatic dependency management (no manual SDL installation required).

## Build & Run

### Prerequisites
- C++20 compatible compiler
- CMake 3.20+

### Instructions (Terminal)
```bash
git clone https://github.com/zekgio/SimpleSnakeSDL3.git
cd SimpleSnakeSDL3
cmake --preset x64-debug
cmake --build --preset x64-debug
./out/build/x64-debug/SimpleSnakeSDL3.exe  (or .\out\build\x64-debug\SimpleSnakeSDL3.exe if on Windows)
```

### Credits
- Inspired by "The Builder" youtube tutorials

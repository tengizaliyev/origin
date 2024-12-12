# CMakeLists.txt : CMake project for FigureProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Название проекта
project ("FigureProject")

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл и его исходники
add_executable(FigureProject
    FigureProject.cpp
    Triangle.h
    Triangle.cpp
    RightTriangle.cpp
    RightTriangle.h
    IsoscelesTriangle.cpp
    IsoscelesTriangle.h
    EquilateralTriangle.cpp
    EquilateralTriangle.h
    Quadrilateral.cpp
    Quadrilateral.h
    myRectangle.cpp
    myRectangle.h
    Square.cpp
    Square.h
)

# TODO: Add tests and install targets if needed.

cmake_minimum_required(VERSION 3.16)

project(IntroProg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(IntroProg main.cpp
    kap02FunkOchCppfiler.cpp
    kap03Variabler.cpp
    kap04FunkInUt.cpp
    kap05ifSatser.cpp
    kap06Flyttal.cpp
    kap07Heltal.cpp
    kap08TestaKod.cpp
    kap09MerOmVariabler.cpp
    kap10MerOmFunktioner.cpp
    kap12Loopar.cpp
    kap13charOchString.cpp
)

include(GNUInstallDirs)
install(TARGETS IntroProg
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
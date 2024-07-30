cmake_minimum_required(VERSION 3.28)
project(cairomotion)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(thirdparty/ink-stroke-modeler)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(cairomotion main.cpp
        CairoMotion.cpp
        CairoMotion.h
        ui/Widget.cpp
        ui/Widget.h
        ui/PopupBar.cpp
        ui/PopupBar.h
        ui/Window.cpp
        ui/Window.h
)

target_link_libraries(cairomotion ${GTKMM_LIBRARIES})

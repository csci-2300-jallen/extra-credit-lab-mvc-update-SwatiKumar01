cmake_minimum_required(VERSION 3.21)
project(QtHello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

set(APP_SOURCES
    src/main.cpp

    src/model/Robot.cpp
    src/model/Robot.h
    src/model/Point2D.h

    src/controller/RobotController.cpp
    src/controller/RobotController.h

    src/view/RobotGridWidget.cpp
    src/view/RobotGridWidget.h
    src/view/RobotWindow.cpp
    src/view/RobotWindow.h
)

add_executable(app ${APP_SOURCES})

target_include_directories(app PRIVATE src)

target_link_libraries(app PRIVATE Qt6::Widgets)

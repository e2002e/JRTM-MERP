cmake_minimum_required(VERSION 3.16)
project(MerpAssistant VERSION 1.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(MerpAssistant WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_compile_definitions(MerpAssistant PRIVATE
    QT_DEPRECATED_WARNINGS
)

target_link_libraries(MerpAssistant PRIVATE
    Qt::Core
    Qt::Gui
)

set_property(TARGET MerpAssistant APPEND PROPERTY
    QT_ANDROID_VERSION_CODE 8)
set_property(TARGET MerpAssistant APPEND PROPERTY
    QT_ANDROID_VERSION_NAME SDK33)
set_property(TARGET MerpAssistant APPEND PROPERTY
    QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
)

# Resources:
set(qmake_immediate_resource_files
    "languages"
)

qt_add_resources(MerpAssistant "qmake_immediate"
    PREFIX
        "/"
    FILES
        ${qmake_immediate_resource_files}
)

if((QT_VERSION_MAJOR GREATER_EQUAL 6))
    target_link_libraries(MerpAssistant PRIVATE
        Qt::Widgets
    )
else()
    if(ANDROID)
        add_library(MerpAssistant SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MerpAssistant
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MerpAssistant PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS MerpAssistant
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MerpAssistant)
endif()

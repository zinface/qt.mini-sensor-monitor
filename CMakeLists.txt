cmake_minimum_required(VERSION 3.5)

project(simple-sensor-monitor VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        resources.qrc
        minifloatingwindow.h minifloatingwindow.cpp minifloatingwindow.ui
        minifloatingicon.h minifloatingicon.cpp
        sensorsworker.h sensorsworker.cpp
        sensorsmanager.h sensorsmanager.cpp
        sensorsmonitor.h sensorsmonitor.cpp
        simplesensormonitor.h simplesensormonitor.cpp
        sensorsettingdialog.h sensorsettingdialog.cpp sensorsettingdialog.ui
        configutil.h configutil.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(simple-sensor-monitor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(simple-sensor-monitor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(simple-sensor-monitor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled)
endif()
set_target_properties(simple-sensor-monitor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS simple-sensor-monitor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(simple-sensor-monitor)
endif()

include(cmake/SparkDesktopMacros.cmake)

# 注释行(使用方式)
find_package(SparkDebPackage PATHS ${CMAKE_SOURCE_DIR})
add_package_descript(cmake/spark-deb-package.descript)

include(cmake/SparkAppimageConfig.cmake)  # 导入来自 Spark 构建的 Appimage 构建
add_appimage_icon(sensor_icon.png)       # 添加到 Appimage 中的默认的图标
add_appimage_desktop()                    # 添加到 Appimage 中的默认desktop(使用来自 Spark 构建的 Desktop 构建中配置的信息(必须要求 spark-desktop))
add_appimage_target(simple-sensor-monitor)      # 添加到 Appimage 中的默认目标，应用对 Appimage 的构建
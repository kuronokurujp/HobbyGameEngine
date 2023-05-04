CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(Game CXX)
message("project name is automaically set as: ${PROJECT_NAME}")

set(PROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# コンパイルしたいソースファイルを記述
set(cmake_training_SRC
  Game/Source/Main.cpp
)

# HobbyEngineのライブラリを取り込むためにEngineのCMakeLists.txtがあるディレクトリを指定
add_subdirectory(./Engine)

# ソースファイルとヘッダーファイルを定義したのを指定
# 実行ファイル名はmain
add_executable(Game ${cmake_training_SRC})

target_link_libraries(Game HobbyEngine)

# メッセージを出力
MESSAGE(STATUS "--------------------------------------------")
MESSAGE(STATUS "Info :")
MESSAGE(STATUS "  Project Name = ${PROJECT_NAME}")
MESSAGE(STATUS "  Version =     ${PROJECT_VERSION}")
MESSAGE(STATUS "  CMAKE_VERSION =        ${CMAKE_VERSION}")
MESSAGE(STATUS "  CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "  CMAKE_BUILD_TYPE =     ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "  CMAKE_INSTALL_LIBDIR = ${CMAKE_INSTALL_LIBDIR}")
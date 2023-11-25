CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
# cppを使うプロジェクト
project(HobbyEngine
    VERSION 1.0.0
    DESCRIPTION "Hobby GameEngine"
    LANGUAGES CXX
)

message("project name is automaically set as: ${PROJECT_NAME}")

# General source files
file(GLOB SOURCE_FILES
  ${HobbyEngine_SOURCE_DIR}/Source/*.cpp)

# C++のコンパイル対象のc++コードファイルを指定
# 静的ライブラリで作成
add_library(HobbyEngine STATIC ${SOURCE_FILES})

# SDL取り込む
add_subdirectory(Dependencies/SDLModule/SDL)

# C++ 17を利用
target_compile_features(HobbyEngine PRIVATE cxx_std_17)
# includeディレクトリを利用者側から#includeで取り込めるようにしている
target_include_directories(HobbyEngine INTERFACE ${HobbyEngine_SOURCE_DIR}/include)

set (SDL3_DIR "${HobbyEngine_SOURCE_DIR}/Dependencies/SDLModule/SDL")
target_include_directories(HobbyEngine PRIVATE
    ${SDL3_DIR}/include
)

set (SDL3_BIN_DIR "${HobbyEngine_BINARY_DIR}/Dependencies/SDLModule/SDL")
set (SDL_DLLFILE ${SDL3_BIN_DIR}/SDL3.dll)
# SDL3.dllをBuildディレクトリにインストール
install(FILES ${SDL_DLLFILE} DESTINATION ${CMAKE_BINARY_DIR})


# すでにビルド済みのSDLのdllファイルがあればそれを参照
# 初期環境構築ではBuildディレクトリにSDLのDllファイルがない事でインストールが失敗するための対策
set (SDL_LINK_DLLFILE ${CMAKE_BINARY_DIR}/SDL3.dll)
if (NOT EXISTS ${SDL_LINK_DLLFILE})
    set (SDL_LINK_DLLFILE ${SDL_DLLFILE})
endif()

# リンクさせるライブラリ(静的 / 動的)を指定
target_link_libraries(HobbyEngine
    ${SDL_LINK_DLLFILE}
    # OpenGLを利用予定
    OpenGL32
)


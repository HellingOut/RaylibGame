cmake_minimum_required(VERSION 3.10)
project(RaylibGame)

# Указываем стандарт языка
set(CMAKE_CXX_STANDARD 20)

#указываем пути к подключаемым файлам
include_directories(${CMAKE_SOURCE_DIR}/libs/raylib/include/)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(RAYLIB ${CMAKE_SOURCE_DIR}/libs/raylib/lib/mingw/libraylib.a)
set(RAYLIB ${CMAKE_SOURCE_DIR}/libs/raylib/lib/mingw/libraylibdll.a)
set(DLL_PATH ${CMAKE_SOURCE_DIR}/libs/raylib/lib/mingw/raylib.dll)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
set(RAYLIB ${CMAKE_SOURCE_DIR}/libs/raylib/lib/vc16/raylib.lib)
set(RAYLIB ${CMAKE_SOURCE_DIR}/libs/raylib/lib/vc16/raylibdll.lib)
set(DLL_PATH ${CMAKE_SOURCE_DIR}/libs/raylib/lib/vc16/raylib.dll)
endif()

# Добавляем исходные файлы
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

# Создаем исполняемый файл
add_executable(MyApp ${SOURCES} ${HEADERS})
target_link_libraries(MyApp PRIVATE ${RAYLIB})


# Путь к файлу .dll
add_custom_command(TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DLL_PATH} $<TARGET_FILE_DIR:MyApp>
    COMMENT "Copying raylib.dll to output directory"
)

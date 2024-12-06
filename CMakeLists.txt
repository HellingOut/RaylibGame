cmake_minimum_required(VERSION 3.10)
project(RaylibGame)

# Указываем стандарт языка
set(CMAKE_CXX_STANDARD 20)

#указываем пути к подключаемым файлам
include_directories(${CMAKE_SOURCE_DIR}/libs/raylib/include/)
include_directories(${CMAKE_SOURCE_DIR}/include/)

set(RAYLIB ${CMAKE_SOURCE_DIR}/libs/raylib/lib/libraylib.a)
set(RAYLIB ${CMAKE_SOURCE_DIR}/libs/raylib/lib/libraylibdll.a)

# Добавляем исходные файлы
file(GLOB_RECURSE SOURCES src/*.cpp)

# Создаем исполняемый файл
add_executable(MyApp ${SOURCES})
target_link_libraries(MyApp PRIVATE ${RAYLIB})


# Путь к файлу .dll
set(DLL_PATH ${CMAKE_SOURCE_DIR}/libs/raylib/lib/raylib.dll)
add_custom_command(TARGET MyApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DLL_PATH} $<TARGET_FILE_DIR:MyApp>
    COMMENT "Copying raylib.dll to output directory"
)

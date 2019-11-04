cmake_minimum_required(VERSION 3.4)

project(Binary_CLI)

#ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES
        src/main.cpp
        )

#add following files to executable file 'Program'
add_executable(Binary_CLI ${SOURCE_FILES})

#add libraries from 'Library' project
target_link_libraries(Binary_CLI Library)

#dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Binary_CLI PUBLIC include)

cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/model/Encryption/Encryption.cpp
        include/model/Encryption/Encryption.h
        src/model/Encryption/DataStandardEncryption.cpp
        include/model/Encryption/DataStandardEncryption.h
        src/model/Key.cpp include/model/Key.h
        src/model/helperFunctions.cpp
        include/model/helperFunctions.h
        )

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

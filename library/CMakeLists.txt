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


if (UNIX)

#Unit Tests section

find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/model/Encryption/DESEncryptionTest.cpp
        test/model/KeyTest.cpp
        test/model/helperFunctionsTest.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest Test
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

#add_test(LibraryTest Test)

endif (UNIX)
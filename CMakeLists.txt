cmake_minimum_required(VERSION 3.15)
project(DESEncryption)

set(CMAKE_CXX_STANDARD 14)

add_executable(DESEncryption main.cpp classes/Cryption/Cryption.cpp classes/Cryption/Cryption.h classes/Cryption/DataEncryptionStandard.cpp classes/Cryption/DataEncryptionStandard.h)
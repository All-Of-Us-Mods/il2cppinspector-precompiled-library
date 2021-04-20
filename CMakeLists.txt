CMAKE_MINIMUM_REQUIRED(VERSION 3.18)

SET(HOOK_SRC .)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_ANDROID_NDK ${ANDROID_NDK}/platform)
SET(CMAKE_TOOLCHAIN_FILE ${ANDROID_NDK}/build/cmake/android.toolchain.cmake)
SET(ANDROID_PLATFORM 19)
SET(ANDROID_ABI armeabi-v7a)
SET(DOBBY_LIB_PATH ${DOBBY_PATH}/build_for_android_arm)

PROJECT(il2cpp-pointers)

file(GLOB_RECURSE SOURCES
        ${HOOK_SRC}/**.cpp)

link_libraries("-llog")

include_directories(assets)
include_directories(include)

ADD_LIBRARY(${CMAKE_PROJECT_NAME} STATIC ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} android)

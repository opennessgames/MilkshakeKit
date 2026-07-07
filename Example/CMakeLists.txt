#
# @Author: xixi_
# @Date: 2026-02-12 00:11:09
# @LastEditors: xixi_
# @LastEditTime: 2026-07-08 03:25:44
# @FilePath: /MilkshakeKit/Example/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(MilkshakeKitExamples VERSION 0.0.1 DESCRIPTION "示例" LANGUAGES C)

# C/C++标准
set(CMAKE_C_STANDARD 23)

# error while loading shared libraries: libXncutCore.so: cannot open shared object file: No such file or directory
set(CMAKE_BUILD_RPATH "$ORIGIN")


# 集中重定向
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR}/Example)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR}/Example)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR}/Example)

# HashMap
add_executable(MilkshakeHashMapExample MilkshakeHashMapExample.c)
target_link_libraries(MilkshakeHashMapExample PRIVATE MilkshakeSTL)

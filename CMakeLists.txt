#
# @Author: xixi_
# @Date: 2025-09-24 19:06:13
# @LastEditors: xixi_
# @LastEditTime: 2026-07-08 03:20:11
# @FilePath: /MilkshakeKit/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(MilkshakeKit VERSION 0.0.1 DESCRIPTION "MilkshakeKit" LANGUAGES C)

set(CMAKE_BUILD_TYPE "MinSizeRel") # 调试(Debug); 发布(Release MinSizeRel)模式
set(CMAKE_C_FLAGS_MINSIZEREL "-O3 -s -fPIE -pie")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-O3 -s -fPIE -pie")
# 链接时删除无用段, 避免 strings Xncut | grep ".cpp" 暴露出cpp
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")
# 剥离符号表，禁用符号导出
set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wl,--strip-all -Wl,--exclude-libs,ALL")
set(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} -Wl,--strip-all -Wl,--exclude-libs,ALL")
# 栈保护
set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_RELEASE} -fstack-protector-strong")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_RELEASE} -fstack-protector-strong")

# 选项
set(MILKSHAKE_KIT_ENABLE_TEST "启用/禁用测试" OFF)

# 输出目录
set(PUBG_XNCUT_BINARY_DIR "Bin" CACHE PATH "二进制文件输出目录")

# 集中重定向
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PUBG_XNCUT_BINARY_DIR})

# Kit
add_subdirectory(Milkshake)

# Exa
add_subdirectory(Example)
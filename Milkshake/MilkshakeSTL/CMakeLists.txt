#
# @Author: xixi_
# @Date: 2026-06-04 20:21:24
# @LastEditors: xixi_
# @LastEditTime: 2026-07-08 03:16:18
# @FilePath: /MilkshakeKit/Milkshake/MilkshakeSTL/CMakeLists.txt
# Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
#

cmake_minimum_required(VERSION 3.19)
project(MilkshakeLinuxSTL VERSION 0.0.1 DESCRIPTION "基础设施库" LANGUAGES C)

add_library(MilkshakeSTL SHARED
    ################################################################################################
    MilkshakeHashMap/MilkshakeHashMap.h
    MilkshakeHashMap/MilkshakeHashMap.c
    ################################################################################################
)

target_include_directories(MilkshakeSTL PUBLIC MilkshakeHashMap)

/*
 * @Author: xixi_
 * @Date: 2026-06-15 16:58:00
 * @LastEditors: xixi_
 * @LastEditTime: 2026-07-08 03:43:22
 * @FilePath: /MilkshakeKit/Example/MilkshakeHashMapExample.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include <MilkshakeHashMap.h>
#include <stdio.h>

typedef struct MStudent
{
    unsigned char Sex;
    int Age;
    char Name[20];
} MStudent;

int main(int argc, char **argv, char **envp)
{
    MilkshakeHashMap *HashMap = MilkshakeHashMapCreate();

    /* 更改哈希算法 */
    HashMap->Hash = MilkshakeHashMapGenerateDJB2Hash;

    /* int */
    {
        MilkshakeHashMapSet(HashMap, "SB", (void *)1134);
        MilkshakeHashMapSet(HashMap, "BB88", (void *)"哦~ Baby别太坏~");
    }
    printf("[str-int] SB: %d\n", (int)(__intptr_t)MilkshakeHashMapGet(HashMap, "SB"));
    printf("[str-int] Sb: %s\n", MilkshakeHashMapGet(HashMap, "Sb") ? "不是空的" : "空的！");
    printf("[str-int] BB88: %s\n", (char *)(__intptr_t)MilkshakeHashMapGet(HashMap, "BB88"));

    /* struct */
    {
        MStudent Student = {
            .0,
            .Age = 114514,
            .Name = "小明",
        };
        MilkshakeHashMapSet(HashMap, "11451", &Student);
    }
    printf("[str-obj] 年龄：%d\n", ((MStudent *)MilkshakeHashMapGet(HashMap, "11451"))->Age);
    printf("[str-obj] 姓名：%s\n", ((MStudent *)MilkshakeHashMapGet(HashMap, "11451"))->Name);

    /* Hash */
    const char *String = "恐龙妈妈提笔忘字~~~~~~~~~~~~~~~~~~";
    printf("[访问哈希函数] %s -> %u\n", String, HashMap->Hash(String)); /* 访问哈希表的哈希函数 */

    /* Free */
    MilkshakeHashMapFree(&HashMap);
    return 0;
}

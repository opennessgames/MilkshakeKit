/*
 * @Author: xixi_
 * @Date: 2025-10-13 00:31:08
 * @LastEditors: xixi_
 * @LastEditTime: 2026-06-21 14:55:08
 * @FilePath: /MilkshakeKit/Milkshake/MilkshakeSTL/MilkshakeHashMap/MilkshakeHashMap.c
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#include "MilkshakeHashMap.h"
#include <stdlib.h>
#include <string.h>

/* DJB2字符串哈希 */
unsigned int MilkshakeHashMapGenerateDJB2Hash(const void *StringPtr)
{
    const char *String = (const char *)StringPtr;
    unsigned int Hash = 5381;

    while (*String)
    {
        Hash = (Hash << 5) + Hash + (unsigned int)(*String++);
    }

    return Hash;
}

unsigned int MilkshakeHashMapGenerateFnv1aHash(const void *StringPtr)
{
    const char *String = (const char *)StringPtr;
    unsigned int Hash = 0x811C9DC5U;

    while (*String)
    {
        Hash ^= (unsigned int)(*String++);
        Hash *= 0x01000193U;
    }

    return Hash;
}

unsigned int MilkshakeHashMapGenerateBKDRHash(const void *StringPtr)
{
    const char *String = (const char *)StringPtr;
    unsigned int Seed = 131; /* 31 131 1313 13131 131313等质数 */
    unsigned int Hash = 0;
    
    while (*String)
    {
        Hash = Hash * Seed + (unsigned int)(*String++);
    }

    return (Hash & 0x7FFFFFFF);
}

MilkshakeHashMap *MilkshakeHashMapCreate()
{
    MilkshakeHashMap *HashMap = (MilkshakeHashMap *)malloc(sizeof(MilkshakeHashMap));

    /* 默认哈希函数 */
    HashMap->Hash = MilkshakeHashMapGenerateDJB2Hash;

    /* 清空桶 */
    for (int i = 0; i < MILKSHAKE_HASH_MAP_BUCKET_MAX; ++i)
    {
        HashMap->NodeBucket[i] = NULL;
    }

    /* 默认释放 */
    HashMap->NodeFree = free;

    return HashMap;
}

MilkshakeHashMapNode *MilkshakeHashMapCreateNode(const void *Key, const void *Val)
{
    MilkshakeHashMapNode *HashMapNode = (MilkshakeHashMapNode *)malloc(sizeof(MilkshakeHashMapNode));
    HashMapNode->NextNode = NULL;
    HashMapNode->Key = (void *)Key;
    HashMapNode->Val = (void *)Val;
    return HashMapNode;
}

int MilkshakeHashMapSet(MilkshakeHashMap *HashMap, const void *Key, const void *Val)
{
    /* 获取字符的哈希值 */
    int Hash = HashMap->Hash(Key) % MILKSHAKE_HASH_MAP_BUCKET_MAX;
    MilkshakeHashMapNode *CurNode = HashMap->NodeBucket[Hash];

    /* 检查键是否存在 */
    while (CurNode)
    {
        if (!strcmp(CurNode->Key, Key))
        {
            CurNode->Val = (void *)Val;
            return 0;
        }
        CurNode = CurNode->NextNode;
    }

    /* 创建新节点 */
    MilkshakeHashMapNode *NewNode = MilkshakeHashMapCreateNode(Key, Val);

    /* 插入到链表头 */
    NewNode->NextNode = HashMap->NodeBucket[Hash];
    HashMap->NodeBucket[Hash] = NewNode;
    return 0;
}

const void *MilkshakeHashMapGet(MilkshakeHashMap *HashMap, const char *Key)
{
    /* 获取字符的哈希值 */
    int Hash = HashMap->Hash(Key) % MILKSHAKE_HASH_MAP_BUCKET_MAX;

    /* 搜索 */
    MilkshakeHashMapNode *CurNode = HashMap->NodeBucket[Hash];
    while (CurNode)
    {
        if (!strcmp(CurNode->Key, Key))
        {
            return CurNode->Val;
        }
        CurNode = CurNode->NextNode;
    }

    return NULL;
}

void MilkshakeHashMapFree(MilkshakeHashMap **HashMap)
{
    for (int i = 0; i < MILKSHAKE_HASH_MAP_BUCKET_MAX; i++)
    {
        MilkshakeHashMapNode *CurNode = (*HashMap)->NodeBucket[i];
        while (CurNode)
        {
            MilkshakeHashMapNode *NextNode = CurNode->NextNode;
            (*HashMap)->NodeFree(CurNode);
            CurNode = NextNode;
        }
    }

    free(*HashMap);
    *HashMap = NULL;
}

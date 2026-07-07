/*
 * @Author: xixi_
 * @Date: 2025-10-13 00:31:08
 * @LastEditors: xixi_
 * @LastEditTime: 2026-07-08 03:44:53
 * @FilePath: /MilkshakeKit/Milkshake/MilkshakeSTL/MilkshakeHashMap/MilkshakeHashMap.h
 * Copyright (c) 2017-2026 by xixi_ , All Rights Reserved.
 */

#ifndef MILKSHAKE_HASH_MAP_H
#define MILKSHAKE_HASH_MAP_H

/********************************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief 键值对
     **/
    typedef struct MilkshakeHashMapNode
    {
        struct MilkshakeHashMapNode *NextNode;
        void *Key;
        void *Val;
    } MilkshakeHashMapNode;

    /**
     * @brief 哈熙表
     * @note 注意! 这个是为属性面板定制的,
     * @note
     * @note 江湖规矩：绝对不能用在服务器中,
     * @note 请使用SipHash + Vector哈希表
     * @note 时间复杂度的真相：
     * @note 哈希表的均摊时间复杂度为 O(1),
     * @note
     * @note 受很多因素的影响,
     * @note 键的类型(字符串, 数字, 复合大对象)和
     * @note 处理冲突方案(链表, 开放寻址, 红黑树)
     * @note 以使用链表法解决冲突的哈希表为例:
     * @note 最好情况下是O(k), k是字符串宽度, 因为哈希字符串需要时间;
     * @note 最坏的情况下是O(k * m),
     * @note m是链表的最大宽度，每一个节点都需要比较字符串。
     * @note 可不可以取最大，不可以，因为两者的最大宽度不是恒定的，
     * @note 有可能字符串太宽，也有可能链表太宽，无法预测。
     * @note
     * @note 使用定宽类型(数字, UUID或者枚举作为键),
     * @note 此时最好的时间复杂度才是O(1)
     * @note 最坏的时间复杂度依然是O(m), m是链表的最大宽度
     * @note 因此, 哈希表并不是绝对的O(1).
     * @note 如果自定义哈希函数: HashMap->Hash = Md5, 完了，这就不是Md5了，成“妈的5”了
     **/
    typedef struct MilkshakeHashMap
    {
        /* 哈希桶 */
#define MILKSHAKE_HASH_MAP_BUCKET_MAX 199
        MilkshakeHashMapNode *NodeBucket[MILKSHAKE_HASH_MAP_BUCKET_MAX];

        /* 自定义哈希函数 */
        unsigned int (*Hash)(const void *Key);

        /* 自定义节点释放 */
        void (*NodeFree)(void *);
    } MilkshakeHashMap;
    /********************************************************************************************************/

    /* Built-in hash functions */
    extern unsigned int MilkshakeHashMapGenerateDJB2Hash(const void *StringPtr);  /* DJB2 */
    extern unsigned int MilkshakeHashMapGenerateFnv1aHash(const void *StringPtr); /* Fnv-1A */
    extern unsigned int MilkshakeHashMapGenerateBKDRHash(const void *StringPtr);  /* BKDR */
    /********************************************************************************************************/

    extern MilkshakeHashMap *MilkshakeHashMapCreate();
    /********************************************************************************************************/

    extern int MilkshakeHashMapSet(MilkshakeHashMap *HashMap, const void *Key, const void *Val);
    extern const void *MilkshakeHashMapGet(MilkshakeHashMap *HashMap, const char *Key);
    /********************************************************************************************************/

    extern void MilkshakeHashMapFree(MilkshakeHashMap **HashMap);
    /********************************************************************************************************/

    /********************************************************************************************************/

    /********************************************************************************************************/

#ifdef __cplusplus
}
#endif
/********************************************************************************************************/

#endif // MILKSHAKE_HASH_MAP_H

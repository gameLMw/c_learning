#include <stdlib.h>
#include "tree.h"
#include "common.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

/* MakeEmpty: 释放整棵树 */
/* Precondition: T 为有效树或 NULL */
/* Postcondition: 所有节点释放，返回 NULL */
SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

/* Find: 查找 X */
/* Precondition: T 为有效树 */
/* Postcondition: 返回指向 X 的节点，或 NULL */
Position Find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

/* FindMin: 找最小值（最左节点） */
/* Precondition: T != NULL */
/* Postcondition: 返回最小元素节点 */
Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

/* FindMax: 找最大值（最右节点） */
/* Precondition: T != NULL */
/* Postcondition: 返回最大元素节点 */
Position FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

/* Insert: 插入 X */
/* Precondition: T 为有效树 */
/* Postcondition: X 被插入（若不存在）并返回新树根 */
SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of memory!");
        T->Element = X;
        T->Left = T->Right = NULL;
    }
    else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);
    // 若 X == T->Element，不插入（集合性质）
    return T;
}

/* Delete: 删除 X */
/* Precondition: T != NULL */
/* Postcondition: X 被删除（若存在） */
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        Error("Element not found");
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right)
    { // 两个子节点
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else
    { // 0 或 1 个子节点
        TmpCell = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    return T;
}

/* Retrieve: 获取节点元素 */
/* Precondition: P != NULL */
/* Postcondition: 返回 P->Element */
ElementType Retrieve(Position P)
{
    return P->Element;
}
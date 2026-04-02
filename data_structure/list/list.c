#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "common.h"

struct Node
{
    ElementType Element;
    Position Next;
};

/* MakeEmpty: 清空列表（保留头节点） */
/* Precondition: L 已通过 MakeEmpty 或 Create 初始化 */
/* Postcondition: L 仅含头节点，Next = NULL */
List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if (L == NULL)
        FatalError("Out of memory!");
    L->Next = NULL;
    return L;
}

/* IsEmpty: 判断表是否为空（仅含头节点） */
/* Precondition: L != NULL */
/* Postcondition: 返回 1 若 L->Next == NULL，否则 0 */
int IsEmpty(List L)
{
    return L->Next == NULL;
}

/* IsLast: 判断 P 是否为最后一个元素 */
/* Precondition: P != NULL */
/* Postcondition: 返回 1 若 P->Next == NULL */
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* Find: 查找元素 X，返回其位置 */
/* Precondition: L != NULL */
/* Postcondition: 返回指向 X 的节点指针，若未找到返回 NULL */
Position Find(ElementType X, List L)
{
    Position P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

/* Delete: 删除第一个值为 X 的节点 */
/* Precondition: L != NULL */
/* Postcondition: 若 X 存在，则删除其首次出现的节点 */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* FindPrevious: 辅助函数，返回 X 前驱位置 */
Position FindPrevious(ElementType X, List L)
{
    Position P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

/* Insert: 在位置 P 后插入 X */
/* Precondition: L != NULL, P != NULL */
/* Postcondition: 新节点插入 P 之后 */
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FatalError("Out of memory!");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* DeleteList: 释放整个列表（包括头节点） */
/* Precondition: L != NULL */
/* Postcondition: 所有节点内存被释放，L 不再有效 */
void DeleteList(List L)
{
    Position P, Tmp;
    P = L;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

/* Header: 返回头节点位置 */
/* Precondition: L != NULL */
/* Postcondition: 返回 L（头节点指针） */
Position Header(List L) { return L; }

/* First: 返回第一个实际元素位置 */
/* Precondition: L != NULL */
/* Postcondition: 返回 L->Next */
Position First(List L) { return L->Next; }

/* Advance: 返回 P 的下一个位置 */
/* Precondition: P != NULL */
/* Postcondition: 返回 P->Next */
Position Advance(Position P) { return P->Next; }

/* Retrieve: 获取位置 P 的元素值 */
/* Precondition: P != NULL 且 P 不是头节点 */
/* Postcondition: 返回 P->Element */
ElementType Retrieve(Position P) { return P->Element; }
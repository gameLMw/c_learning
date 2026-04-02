#include <stdlib.h>
#include "stack.h"
#include "common.h"

#define MinStackSize 5

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Elements;
};

/* CreateStack: 创建容量为 MaxElements 的栈 */
/* Precondition: MaxElements > MinStackSize */
/* Postcondition: 返回初始化的栈，TopOfStack = -1 */
Stack CreateStack(int MaxElements)
{
    Stack S;
    if (MaxElements < MinStackSize)
        Error("Stack size is too small");
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL)
        FatalError("Out of memory!");
    S->Elements = malloc(sizeof(ElementType) * MaxElements);
    if (S->Elements == NULL)
        FatalError("Out of memory!");
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

/* DisposeStack: 释放栈内存 */
/* Precondition: S != NULL */
/* Postcondition: S 及其 Elements 被释放 */
void DisposeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Elements);
        free(S);
    }
}

/* IsEmpty: 判断栈是否为空 */
/* Precondition: S != NULL */
/* Postcondition: 返回 1 若 TopOfStack == -1 */
int IsEmpty(Stack S) { return S->TopOfStack == -1; }

/* IsFull: 判断栈是否满 */
/* Precondition: S != NULL */
/* Postcondition: 返回 1 若 TopOfStack == Capacity - 1 */
int IsFull(Stack S) { return S->TopOfStack == S->Capacity - 1; }

/* MakeEmpty: 清空栈 */
/* Precondition: S != NULL */
/* Postcondition: TopOfStack = -1 */
void MakeEmpty(Stack S) { S->TopOfStack = -1; }

/* Push: 压入元素 X */
/* Precondition: S != NULL 且 !IsFull(S) */
/* Postcondition: X 成为栈顶 */
void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        Error("Full stack");
    else
        S->Elements[++S->TopOfStack] = X;
}

/* Top: 返回栈顶元素（不弹出） */
/* Precondition: S != NULL 且 !IsEmpty(S) */
/* Postcondition: 返回栈顶元素 */
ElementType Top(Stack S)
{
    if (IsEmpty(S))
        Error("Empty stack");
    return S->Elements[S->TopOfStack];
}

/* Pop: 弹出栈顶 */
/* Precondition: S != NULL 且 !IsEmpty(S) */
/* Postcondition: 栈顶指针下移 */
void Pop(Stack S)
{
    if (IsEmpty(S))
        Error("Empty stack");
    else
        S->TopOfStack--;
}

/* TopAndPop: 取出并弹出栈顶 */
/* Precondition: S != NULL 且 !IsEmpty(S) */
/* Postcondition: 返回原栈顶，并弹出 */
ElementType TopAndPop(Stack S)
{
    if (IsEmpty(S))
        Error("Empty stack");
    return S->Elements[S->TopOfStack--];
}
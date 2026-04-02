#ifndef STACK_H
#define STACK_H

#include "common.h"

struct StackRecord;
typedef struct StackRecord *Stack;

Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
int IsEmpty(Stack S);
int IsFull(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif
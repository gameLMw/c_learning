#include <stdio.h>
#include <stdlib.h>
#include "qeueue.h"

// 局部函数原型声明
// 将元素复制到节点
// item: 要复制的元素
// pn: 指向目标节点的指针
static void CopyToNode(Item item, Node *pn);
// 将节点中的元素复制到指定位置
// pn: 指向源节点的指针
// pi: 指向目标位置的指针
static void CopyToTtem(Node *pn, Item *pi);

void InitializeQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
    Node *pnew;
    if (QueueIsFull(pq))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq))
    {
        pq->front = pnew;
    }
    else
    {
        pq->rear->next = pnew;
        pq->rear = pnew;
        pq->items++;
    }

    return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt;

    if (QueueIsEmpty(pq))
        return false;
    CopyToTtem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;

    return true;
}

void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}

static void CopyToTtem(Node *pn, Item *pi)
{
    *pi = pn->item;
}

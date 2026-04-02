#include <stdlib.h>
#include "queue.h"
#include "common.h"

#define MinQueueSize 5

struct QueueRecord
{
    int Capacity;
    int Front, Rear;
    int Size;
    ElementType *Array;
};

Queue CreateQueue(int MaxElements)
{
    Queue Q;
    if (MaxElements < MinQueueSize)
        Error("Queue size too small");
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of memory!");
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL)
        FatalError("Out of memory!");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

int IsEmpty(Queue Q) { return Q->Size == 0; }
int IsFull(Queue Q) { return Q->Size == Q->Capacity; }

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

/* Enqueue: 入队 */
/* Precondition: Q != NULL 且 !IsFull(Q) */
/* Postcondition: X 加入队尾 */
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue");
    else
    {
        Q->Rear = (Q->Rear + 1) % Q->Capacity;
        Q->Array[Q->Rear] = X;
        Q->Size++;
    }
}

/* Front: 查看队首（不删除） */
/* Precondition: Q != NULL 且 !IsEmpty(Q) */
/* Postcondition: 返回队首元素 */
ElementType Front(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue");
    return Q->Array[Q->Front];
}

/* Dequeue: 出队 */
/* Precondition: Q != NULL 且 !IsEmpty(Q) */
/* Postcondition: 队首元素被移除 */
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue");
    else
    {
        Q->Front = (Q->Front + 1) % Q->Capacity;
        Q->Size--;
    }
}

/* FrontAndDequeue: 出队并返回队首 */
/* Precondition: Q != NULL 且 !IsEmpty(Q) */
/* Postcondition: 返回原队首并移除 */
ElementType FrontAndDequeue(Queue Q)
{
    ElementType X;
    if (IsEmpty(Q))
        Error("Empty queue");
    X = Q->Array[Q->Front];
    Q->Front = (Q->Front + 1) % Q->Capacity;
    Q->Size--;
    return X;
}
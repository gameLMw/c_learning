#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif
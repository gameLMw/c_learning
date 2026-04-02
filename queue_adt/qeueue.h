#ifndef QUEUE_H_
#define QUEUE_H_
#define MAXQUEUE 10 // 队列的最大容量
#include <stdbool.h>

typedef int Item; // 队列元素类型定义

typedef struct node
{
    Item item;
    struct node *next;
} Node; // 节点结构体定义

typedef struct queue
{
    Node *front; // 队列头指针
    Node *rear;  // 队列尾指针
    int items;   // 队列中当前元素个数
} Queue;         // 队列结构体定义

// 函数原型声明
// 初始化队列
// pq: 指向要初始化的队列的指针
void InitializeQueue(Queue *pq);

// 判断队列是否已满,已满返回true，否则返回false
// pq: 指向要检查的队列的指针
bool QueueIsFull(const Queue *pq);

// 判断队列是否为空，为空返回true，否则返回false
// pq: 指向要检查的队列的指针
bool QueueIsEmpty(const Queue *pq);

// 获取队列中元素个数，返回元素个数
// pq: 指向要检查的队列的指针
int QueueItemCount(const Queue *pq);

// 入队操作，返回true表示入队成功，false表示入队失败
// item: 要入队的元素
// pq: 指向要操作的队列的指针
bool EnQueue(Item item, Queue *pq);

// 出队操作，返回true表示出队成功，false表示出队失败
// pitem: 指向存放出队元素的指针，返回pq的元素
// pq: 指向要操作的队列的指针
bool DeQueue(Item *pitem, Queue *pq);

// 清空队列，释放内存
// pq: 指向要清空的队列的指针
void EmptyTheQueue(Queue *pq);

#endif
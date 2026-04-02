#ifndef LIST_H_ // 中文
#define LIST_H_
#include <stdbool.h>

// 特定程序的声名

#define TSIZE 45 // 储存电影名称的数组大小
// 电影结构
struct film
{
    char title[TSIZE]; // 电影名称
    int rating;        // 评分
};

// 一般类型定义

typedef struct film Item;

// 链表节点结构
typedef struct node
{
    Item item;         // 链表中的项
    struct node *next; // 指向下一个节点的指针
} Node;

// 链表类型定义
typedef Node *List;

// 函数原型
// 操作：初始化一个链表
// 前置条件：plist指向一个链表
// 后置条件：链表被初始化为空
void InitializeList(List *plist);

// 操作：确定链表是否为空，plist指向一个已初始化的链表
// 后置条件：如果链表为空，则返回true，否则返回false
bool ListIsEmpty(const List *plist);

// 操作：确定链表是否已满，plist指向一个已初始化的链表
// 后置条件：如果链表已满，则返回true，否则返回false
bool ListIsFull(const List *plist);

// 操作：确定链表中的项数，plist指向一个已初始化的链表
// 后置条件：返回链表中的项数
unsigned int ListItemCount(const List *plist);

// 操作：在链表末尾添加项
// 前置条件：item是一个要添加到链表的项，plist指向一个已初始化的链表
// 后置条件：如果可以，则在链表末尾添加一个项，并返回true；否则返回false
bool AddItem(const Item *item, List *plist);

// 操作：把函数作用于链表中的每一项，
// plist指向一个已初始化的链表，
// pfun指向一个函数，该函数接受一个Item类型的参数并且无返回值
// 后置条件：pfun指向的函数被作用于链表中的每一项一次
void Traverse(const List *plist, void (*pfun)(Item item));

// 操作：释放为链表分配的内存，plist指向一个已初始化的链表
// 后置条件：释放了为链表分配的内存，链表被置为空
void EmptyTheList(List *plist);

#endif

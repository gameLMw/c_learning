#ifndef GLUTTONOUS_SNAKE_H_
#define GLUTTONOUS_SNAKE_H_
#include <stdbool.h>
#include <windows.h>

#define LENGTH 64              // 地图长度
#define WIDTH 12               // 地图宽度
#define INITIAL_SNAKE_LENGTH 3 // 初始蛇长（INITIAL_SNAKE_LENGTH <= 31）

// 方向
typedef enum Direction
{
    UP,   // 上
    DOWN, // 下
    LEFT, // 左
    RIGHT // 右
} dir;
// 位置
typedef struct Position
{
    int x; // 横坐标
    int y; // 纵坐标
} pos;
// 蛇节点
typedef struct SnakeNode // 蛇节点
{
    pos position;           // 节点位置
    struct SnakeNode *next; // 指向下一个节点的指针
} SnakeNode;
// 蛇
typedef struct Snake
{
    SnakeNode *head; // 蛇头指针
    SnakeNode *tail; // 蛇尾指针
    dir direction;   // 蛇当前方向
    int length;      // 蛇当前长度
} Snake;

// 全局控制台句柄
extern HANDLE g_hConsole;

// 函数声明

// 初始化控制台
void InitializeConsole(void);

// 初始化蛇
// s: Snake指针，指向要初始化的蛇结构体
void InitializeSnake(Snake *s);

// 生成地图数据（不打印）
//  map: 二维字符数组，表示地图
void GenerateMap(char map[WIDTH][LENGTH]);

/*
蛇头初始位置在地图中心，蛇身向右延伸
蛇的初始长度为INITIAL_SNAKE_LENGTH
蛇的初始方向为LEFT（向左）
*/
// s: Snake指针，指向蛇结构体
// map:地图
// 在地图map上生成蛇Snake数据（不打印）
void GenerateSnake(char map[WIDTH][LENGTH], Snake *s);

// 在地图map上生成果实food数据(food与s不能重合，不打印)
//  food: pos指针，指向果实位置结构体
void GenerateFood(char map[WIDTH][LENGTH], pos *food, const Snake *s);

//显示地图
void DisplayMap(char map[WIDTH][LENGTH]);

// 蛇移动
// s: Snake指针，指向蛇结构体
void MoveSnake(Snake *s, bool eatFood);

// 输出蛇现有的长度
// s: Snake指针，指向蛇结构体
int SnakeItemCount(const Snake *s);

// 清空队列，释放内存
// s: Snake指针，指向蛇结构体
void DestroySnake(Snake *s); 

#endif

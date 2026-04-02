#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "GluttonousSnake.h"

// (x,Y)重合
// 重合返回1，不重合返回0
static bool Superposition(const pos *p, const Snake *s);

// 全局控制台句柄
HANDLE g_hConsole = INVALID_HANDLE_VALUE;

void InitializeConsole(void)
{
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (g_hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "无法获取控制台句柄！\n");
        exit(1);
    }

    // 隐藏光标
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(g_hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(g_hConsole, &cursorInfo);
}

void InitializeSnake(Snake *s)
{
    s->head = NULL;
    s->tail = NULL;
    s->direction = LEFT;
    s->length = 0;
}

void GenerateMap(char map[WIDTH][LENGTH])
{
    for (int i = 0; i < LENGTH; i++)
    {
        map[0][i] = '#';
    }
    for (int i = 0; i < WIDTH - 2; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            if (j == 0 || j == LENGTH - 1)
            {
                map[i + 1][j] = '#';
            }
            else
            {
                map[i + 1][j] = ' ';
            }
        }
    }
    for (int i = 0; i < LENGTH; i++)
    {
        map[WIDTH - 1][i] = '#';
    }
}

void GenerateSnake(char map[WIDTH][LENGTH], Snake *s)
{
    // 生成蛇头
    SnakeNode *newHead = (SnakeNode *)malloc(sizeof(SnakeNode));
    if (newHead == NULL)
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    newHead->position.x = LENGTH / 2;
    newHead->position.y = WIDTH / 2;
    newHead->next = NULL;
    s->head = newHead;
    s->tail = newHead;
    s->length=1;
    map[WIDTH / 2][LENGTH / 2] = '@';
    // 生成蛇身
    for (int i = 1; i < INITIAL_SNAKE_LENGTH; i++)
    {
        SnakeNode *SnakeBody = (SnakeNode *)malloc(sizeof(SnakeNode));
        if (SnakeBody == NULL)
        {
            printf("内存分配失败！\n");
            exit(1);
        }
        SnakeBody->position.x = LENGTH / 2 + i;
        SnakeBody->position.y = WIDTH / 2;
        SnakeBody->next = NULL;
        s->tail->next = SnakeBody;
        s->tail = SnakeBody;
        s->length++;
        map[WIDTH / 2][LENGTH / 2 +i] = '*';
    }
    // 蛇初始方向
    s->direction = LEFT;
}

void GenerateFood(char map[WIDTH][LENGTH], pos *food, const Snake *s)
{
    //srand((unsigned)time(NULL));
    do
    {
        food->x = 1 + rand() %(LENGTH-2);
        food->y = 1 + rand() % (WIDTH-2);
    } while (Superposition(food, s));
    map[food->y][food->x] = '$';
}

void DisplayMap(char map[WIDTH][LENGTH])
{
    // 使用Windows API清屏
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    
    // 获取控制台缓冲区大小
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    
    // 填充空格
    FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    
    // 设置光标位置到左上角
    SetConsoleCursorPosition(hConsole, coordScreen);
    
    // 打印地图
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}


void MoveSnake(Snake *s, bool eatFood)
{
    if (!s || !s->head) return;

    pos newHead = s->head->position;
    switch (s->direction) {
        case UP:    newHead.y--; break;
        case DOWN:  newHead.y++; break;
        case LEFT:  newHead.x--; break;
        case RIGHT: newHead.x++; break;
    }

    // 检查是否撞墙（地图边界为 0 和 LENGTH-1 / WIDTH-1，内部可走区域为 [1, LENGTH-2] × [1, WIDTH-2]）
    if (newHead.x <= 0 || newHead.x >= LENGTH - 1 ||
        newHead.y <= 0 || newHead.y >= WIDTH - 1) {
        return; // 撞墙，不移动（可后续扩展为游戏结束）
    }

    // 创建新头节点
    SnakeNode *newNode = malloc(sizeof(SnakeNode));
    if (!newNode) {
        fprintf(stderr, "内存分配失败！\n");
        exit(1);
    }
    newNode->position = newHead;
    newNode->next = s->head;
    s->head = newNode;

    if (eatFood) {
        s->length++; // 吃到食物，蛇变长
    } else {
        // 未吃食物：删除尾节点
        SnakeNode *prev = s->head;
        while (prev->next != s->tail) {
            prev = prev->next;
        }
        free(s->tail);
        s->tail = prev;
        s->tail->next = NULL;
        // 长度不变（头增尾删），无需修改 s->length
    }
}




int SnakeItemCount(const Snake *s)
{
    return s ? s->length : 0;
}

void DestroySnake(Snake *s)
{
    if (!s) return false;
    SnakeNode *cur = s->head;
    while (cur) {
        SnakeNode *next = cur->next;
        free(cur);
        cur = next;
    }
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;
    return true;
}

//内置函数
static bool Superposition(const pos *p, const Snake *s)
{
    SnakeNode *temp = s->head;
    while (temp != NULL)
    {
        if (p->x == temp->position.x && p->y == temp->position.y)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

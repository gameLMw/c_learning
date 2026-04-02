#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "GluttonousSnake.h"

// (x,Y)重合
// 重合返回1，不重合返回0
static bool Superposition(const pos *p, const Snake *s);

// 内部辅助：定位光标到 (x, y)
// x: 横坐标（列），范围 [0, LENGTH)
// y: 纵坐标（行），范围 [0, WIDTH)
static void gotoxy(int x, int y);

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
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
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
    s->length++;
    map[LENGTH / 2][WIDTH / 2] = '@';
    // 生成蛇身
    for (int i = 1; i <= INITIAL_SNAKE_LENGTH; i++)
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
        map[LENGTH / 2 + i][WIDTH / 2] = '*';
    }
    // 蛇初始方向
    s->direction = LEFT;
}

void GenerateFood(char map[WIDTH][LENGTH], pos *food, const Snake *s)
{
    srand((unsigned)time(NULL));
    do
    {
        food->x = 1 + rand() % 63;
        food->y = 1 + rand() % 11;
    } while (Superposition(food, s));
    map[food->x][food->y] = '$';
}

void DisplayMap(char map[WIDTH][LENGTH])
{
    system("cls");  // Linux/Mac清屏，Windows用system("cls")
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
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

static void gotoxy(int x, int y) 
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(g_hConsole, pos);
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define LENGTH 64              
#define WIDTH 12               
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


void GenerateFood(char map[WIDTH][LENGTH], pos *food, const Snake *s)
{
    srand((unsigned)time(NULL));
    do
    {
        food->x = 1 + rand() %(LENGTH-2);
        food->y = 1 + rand() % (WIDTH-2);
    } while (Superposition(food, s));
    map[food->y][food->x] = '$';
}

int main()
{
    char map[WIDTH][LENGTH];
    GenerateMap(map);
    pos*food=(pos*)malloc(sizeof(pos));
    Snake*s=(Snake*)malloc(sizeof(Snake));
    InitializeSnake(s);
    GenerateSnake(map,s);
    GenerateFood(map,food,s);
    DisplayMap(map);
    return 0;
}
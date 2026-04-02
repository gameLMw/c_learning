#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "GluttonousSnake.h"

#define GAME_SPEED 200 // 游戏速度（毫秒），建议 150~250 之间，避免闪烁

// 仅清空地图内部区域（不包括边框）
static void ClearInnerMap(char map[WIDTH][LENGTH])
{
    for (int y = 1; y < WIDTH - 1; y++)
    {
        for (int x = 1; x < LENGTH - 1; x++)
        {
            map[y][x] = ' ';
        }
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    InitializeConsole();

    // 地图：边框只需初始化一次
    char map[WIDTH][LENGTH];
    GenerateMap(map); // 生成带 # 边框的地图

    // 初始化蛇
    Snake snake;
    InitializeSnake(&snake);
    GenerateSnake(map, &snake); // 在 map 上绘制初始蛇（@ 和 *）

    // 初始化食物
    pos food;
    GenerateFood(map, &food, &snake); // 在 map 上放置 $

    // 首次完整显示
    DisplayMap(map);

    bool gameRunning = true;

    while (gameRunning)
    {
        // 非阻塞读取按键
        if (_kbhit())
        {
            char ch = _getch();
            switch (ch)
            {
                case 'w': case 'W':
                    if (snake.direction != DOWN) snake.direction = UP;
                    break;
                case 's': case 'S':
                    if (snake.direction != UP) snake.direction = DOWN;
                    break;
                case 'a': case 'A':
                    if (snake.direction != RIGHT) snake.direction = LEFT;
                    break;
                case 'd': case 'D':
                    if (snake.direction != LEFT) snake.direction = RIGHT;
                    break;
                case 'q': case 'Q':
                    gameRunning = false;
                    continue; // 不执行移动
                default:
                    break;
            }
        }

        // 计算新蛇头位置
        pos newHead = snake.head->position;
        switch (snake.direction)
        {
            case UP:    newHead.y--; break;
            case DOWN:  newHead.y++; break;
            case LEFT:  newHead.x--; break;
            case RIGHT: newHead.x++; break;
        }

        // 撞墙检测
        if (newHead.x <= 0 || newHead.x >= LENGTH - 1 ||
            newHead.y <= 0 || newHead.y >= WIDTH - 1)
        {
            printf("\n你撞到墙了！游戏结束。\n");
            printf("最终长度: %d\n", SnakeItemCount(&snake));
            break;
        }

        // 自撞检测：新头是否与现有蛇身（包括当前头）重合？
        bool selfCollision = false;
        SnakeNode *cur = snake.head;
        while (cur != NULL)
        {
            if (cur->position.x == newHead.x && cur->position.y == newHead.y)
            {
                selfCollision = true;
                break;
            }
            cur = cur->next;
        }
        if (selfCollision)
        {
            printf("\n你撞到自己了！游戏结束。\n");
            printf("最终长度: %d\n", SnakeItemCount(&snake));
            break;
        }

        // 判断是否吃到食物
        bool willEatFood = (newHead.x == food.x && newHead.y == food.y);

        // 移动蛇（修改链表结构）
        MoveSnake(&snake, willEatFood);

        // 清空地图内部（保留边框）
        ClearInnerMap(map);

        // 重绘蛇：遍历链表
        cur = snake.head;
        if (cur)
        {
            map[cur->position.y][cur->position.x] = '@'; // 蛇头
            cur = cur->next;
            while (cur)
            {
                map[cur->position.y][cur->position.x] = '*'; // 蛇身
                cur = cur->next;
            }
        }

        // 重绘食物（始终显示）
        map[food.y][food.x] = '$';

        // 如果吃到食物，生成新的
        if (willEatFood)
        {
            GenerateFood(map, &food, &snake); // 内部会设置 map[food.y][food.x] = '$'
        }

        // 显示完整地图（含边框#、食物$、蛇@*）
        DisplayMap(map);

        // 控制帧率
        Sleep(GAME_SPEED);
    }

    // 清理资源
    DestroySnake(&snake);

    printf("\n按任意键退出...");
    _getch();

    return 0;
}
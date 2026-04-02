#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void showmovies(Item item);
char *s_gets(char *st, int n);
int main(void) // 中文
{
    List movies;
    Item temp;

    // 初始化链表
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "无法创建链表节点。程序终止。\n");
        exit(1);
    }

    // 获取用户输入并储存
    puts("请输入电影名称(按下0停止)：");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '0')
    {
        puts("请输入你的评分(0-10)：");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(&temp, &movies) == false)
        {
            fprintf(stderr, "无法添加电影。程序终止。\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("链表已满，无法添加更多电影。");
            break;
        }
        puts("请输入下一部电影名称(输入0结束)：");
    }

    // 显示电影列表
    if (ListIsEmpty(&movies))
        printf("没有电影。\n");
    else
    {
        printf("你喜欢的电影有：\n");
        Traverse(&movies, showmovies);
    }
    printf("你总共输入了 %d 部电影。\n", ListItemCount(&movies));

    // 释放链表内存
    EmptyTheList(&movies);
    printf("再见！\n");

    return 0;
}

void showmovies(Item item)
{
    printf("电影：%-45s评分：%d\n", item.title, item.rating);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是NULL
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理输入行中剩余的字符
    }
    return ret_val;
}
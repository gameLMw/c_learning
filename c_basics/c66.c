#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

typedef struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
} film;

char *s_gets(char *st, int n);

int main()
{
    film *head = NULL;
    film *tail = NULL;
    film *new_film = NULL;
    char temp[TSIZE];
    printf("输入电影名(输入0时结束):");
    while (s_gets(temp, TSIZE) && temp[0] != '\0' && temp[0] != '0')
    {
        new_film = (film *)malloc(sizeof(film));
        if (new_film == NULL)
        {
            printf("内存分配失败\n");
            break;
        }
        if (head == NULL)
            head = new_film;
        else
            tail->next = new_film;
        new_film->next = NULL;
        strcpy(new_film->title, temp);
        printf("输入电影评分(1~10):");
        scanf("%d", &new_film->rating);
        while (getchar() != '\n')
            continue;
        if (new_film->rating < 1 || new_film->rating > 10)
        {
            printf("评分无效，设置为5\n");
            new_film->rating = 5;
        }
        printf("输入电影名(输入0时结束):");
        tail = new_film;
    }
    if (head == NULL)
    {
        printf("没有电影数据\n");
        return 0;
    }
    printf("\n你输入的电影列表:\n");
    new_film = head;
    while (new_film != NULL)
    {
        printf("电影: %-45s评分: %d\n", new_film->title, new_film->rating);
        new_film = new_film->next;
    }
    new_film = head;
    while (new_film != NULL)
    {
        head = new_film->next;
        free(new_film);
        new_film = head;
    }
    printf("再见!\n");
    return 0;
}

// 安全获取字符串输入
char *s_gets(char *st, int n)
{
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        char *find;
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
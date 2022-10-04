#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define null NULL
typedef struct student
{
    int sno;
    char sname[10];
    int score;
}stu;

typedef struct linklist
{
    stu data;
    struct linklist* next;
}linklist;

typedef struct list
{
    linklist* head;
}list;

void create(list* list);
void read(list* list);
void find(list* list);
void insert(list* list);
void menu(list* list);
void delete(list* list, int id);

int main()
{
    list list;
    list.head = null;
    printf("第一次使用，请输入所需数据\n");
    create(&list);
    printf("初始化完成！\n");
    menu(&list);
    return 0;
}
//创建链表 
void create(list* list)
{
    linklist* p, * q;
    int i, n;
    printf("请输入学生个数\n");
    scanf("%d", &n);
    printf("请按照学号，姓名，成绩的顺序输入\n");
    for (i = 1; i <= n; i++)
    {
        p = (linklist*)malloc(sizeof(linklist));
        scanf("%d %s %d", &p->data.sno, &p->data.sname, &p->data.score);
        p->next = null;
        if (list->head == null)
            list->head = p;
        else
            q->next = p;
        q = p;
    }
}
//菜单
void menu(list* list)
{
    printf("1.读取所有数据\n");
    printf("2.插入一个新的值\n");
    printf("3.搜索并删除该数据\n");
    printf("4及其他.退出\n");
    printf("输入一个数字，选择选项控制操作\n");
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:read(list);
    case 2:insert(list);
    case 3:find(list);
    default:return 0;
    }
}
//读取 
void read(list* list)
{
    linklist* t;
    t = list->head;
    printf("学号      姓名       成绩\n");
    while (t != null)
    {
        printf("%d %12s %7d\n", t->data.sno, t->data.sname, t->data.score);
        t = t->next;
    }
    menu(list);
}
//插入 
void insert(list* list)
{
    char a;
    linklist* t, * p;
    t = list->head;
    stu add;
    printf("请按照学号，姓名，成绩的顺序输入需要插入的值\n");
    scanf("%d %s %d", &add.sno, &add.sname, &add.score);
    while (t != NULL)
    {
        if (t->next == NULL || t->next->data.sno > add.sno)
        {
            p = (linklist*)malloc(sizeof(linklist));
            p->data.sno = add.sno;
            strcpy(p->data.sname, add.sname);
            p->data.score = add.score;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }
    printf("插入完成\n");
    menu(list);
}
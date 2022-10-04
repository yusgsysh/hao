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
    printf("��һ��ʹ�ã���������������\n");
    create(&list);
    printf("��ʼ����ɣ�\n");
    menu(&list);
    return 0;
}
//�������� 
void create(list* list)
{
    linklist* p, * q;
    int i, n;
    printf("������ѧ������\n");
    scanf("%d", &n);
    printf("�밴��ѧ�ţ��������ɼ���˳������\n");
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
//�˵�
void menu(list* list)
{
    printf("1.��ȡ��������\n");
    printf("2.����һ���µ�ֵ\n");
    printf("3.������ɾ��������\n");
    printf("4������.�˳�\n");
    printf("����һ�����֣�ѡ��ѡ����Ʋ���\n");
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
//��ȡ 
void read(list* list)
{
    linklist* t;
    t = list->head;
    printf("ѧ��      ����       �ɼ�\n");
    while (t != null)
    {
        printf("%d %12s %7d\n", t->data.sno, t->data.sname, t->data.score);
        t = t->next;
    }
    menu(list);
}
//���� 
void insert(list* list)
{
    char a;
    linklist* t, * p;
    t = list->head;
    stu add;
    printf("�밴��ѧ�ţ��������ɼ���˳��������Ҫ�����ֵ\n");
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
    printf("�������\n");
    menu(list);
}
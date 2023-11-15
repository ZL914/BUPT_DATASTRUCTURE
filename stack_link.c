#include <stdio.h>
#include <stdlib.h>
#define ElemType  int
struct node{
    ElemType data;
    struct node* next;
};
typedef struct node node;
//��ʼ��ջ
void stack_creat(node* s)
{
    s->next=NULL;
}
//�ж�ջ��
int stack_empty(node* s)
{
    if(s->next==NULL)
      return 1;
    else
      return 0;
}
//ѹ������
void stack_push(node* s,int data)
{
    node* p=(node*)malloc(sizeof(node));
    p->next=s->next;
    p->data=data;
    s->next=p;
}
//ȡ������
void stack_pop(node* s,int* e)
{
    if(stack_empty(s))
    {
        printf("ջΪ��\n");
    }
    else{
        node* p=(node*)malloc(sizeof(node));
        p=s->next;
        *e=p->data;
        s->next=p->next;
    }
}
//���ջ��Ԫ��
int stack_gettop(node* s)
{
    if(stack_empty(s))
    {
        printf("ջΪ��\n");
        return 0;
    }
    else{
       return s->next->data;
    }
}
//����ջ��
int stack_length(node* s)
{
    if(stack_empty(s))
    {
        printf("ջΪ��\n");
        return 0;
    }
    else{
        int i=0;
        node* p=(node*)malloc(sizeof(node));
        p=s->next;
        while(p!=NULL)
        {
           i++;
           p=p->next;
        }
        return i;
    }
}
//���ջԪ��
void stack_output(node *s)
{
    if(stack_empty(s))
    {
        printf("ջΪ��\n");
    }
    else{
        node* p=(node*)malloc(sizeof(node));
        p=s->next;
        while(p!=NULL)
        {
            printf("%d  ",p->data);
            p=p->next;
        }
    } 
}
//����ջ
void stack_destory(node*s)
{
    node* p=(node*)malloc(sizeof(node));
    while(s->next!=NULL)
    {
        p=s;
        free(p);
        s=s->next;
    }
}

int main()
{
    node* s;
    int count;
    int i=0;
    int data;
    s=(node*)malloc(sizeof(struct node));
    stack_creat(s);
    printf("��������ջ���ݸ���:\n");
    scanf("%d",&count);
    printf("��������ջ����:\n");
    for(i=1;i<=count;i++)
    {
        scanf("%d",&data);
        stack_push(s,data);
    }
    printf("ջ��Ԫ��Ϊ:%d\n",stack_gettop(s));
    printf("ջ����Ϊ:%d\n",stack_length(s));
    stack_pop(s,&i);
    printf("ջ��Ԫ��Ϊ:%d\n",stack_gettop(s));
    printf("ջ����Ϊ:%d\n",stack_length(s));
    stack_output(s);
    stack_destory(s);
    return 0;
}
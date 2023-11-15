#include <stdio.h>
#include <stdlib.h>
#define ElemType  int
struct node{
    ElemType data;
    struct node* next;
};
typedef struct node node;
//初始化栈
void stack_creat(node* s)
{
    s->next=NULL;
}
//判断栈空
int stack_empty(node* s)
{
    if(s->next==NULL)
      return 1;
    else
      return 0;
}
//压入数据
void stack_push(node* s,int data)
{
    node* p=(node*)malloc(sizeof(node));
    p->next=s->next;
    p->data=data;
    s->next=p;
}
//取出数据
void stack_pop(node* s,int* e)
{
    if(stack_empty(s))
    {
        printf("栈为空\n");
    }
    else{
        node* p=(node*)malloc(sizeof(node));
        p=s->next;
        *e=p->data;
        s->next=p->next;
    }
}
//获得栈顶元素
int stack_gettop(node* s)
{
    if(stack_empty(s))
    {
        printf("栈为空\n");
        return 0;
    }
    else{
       return s->next->data;
    }
}
//计算栈长
int stack_length(node* s)
{
    if(stack_empty(s))
    {
        printf("栈为空\n");
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
//输出栈元素
void stack_output(node *s)
{
    if(stack_empty(s))
    {
        printf("栈为空\n");
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
//销毁栈
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
    printf("请输入入栈数据个数:\n");
    scanf("%d",&count);
    printf("请输入入栈数据:\n");
    for(i=1;i<=count;i++)
    {
        scanf("%d",&data);
        stack_push(s,data);
    }
    printf("栈顶元素为:%d\n",stack_gettop(s));
    printf("栈长度为:%d\n",stack_length(s));
    stack_pop(s,&i);
    printf("栈顶元素为:%d\n",stack_gettop(s));
    printf("栈长度为:%d\n",stack_length(s));
    stack_output(s);
    stack_destory(s);
    return 0;
}
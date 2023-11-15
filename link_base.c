#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node node;

node* creatlink(node* head,int n)            //创建双向循环链表
{
    node* p0=(node*)malloc(sizeof(node));
    p0=head;
    p0->next=NULL;
    p0->prev=NULL;
    p0->data=0;
    for(int i=1;i<=10;i++)
    {
        node* p1=(node*)malloc(sizeof(node));
        if(i!=10)
        {
            p1->data=i;
            p0->next=p1;
            p1->next=NULL;
            p1->prev=p0;
            p0=p1;
        }
        else {
            p1->data=i;
            p0->next=p1;
            p1->next=head;
            head->prev=p1;
            p1->prev=p0;
        }
    }
    return head;
}

void print(node* head)                       //末尾换行打印
{
    node* p=NULL;
    p=head;
    while(p->next!=head)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

void finddata(node* head,int i)              //查找第i个元素值
{
    node* p=NULL;
    p=head;
    int j=1;
    for(j=1;j<i;j++)
    {
        p=p->next;
    }
    printf("%d\n",p->data);
}

void deletelink(node* head,int i)            //删除第i位链表
{
    node* p=head;
    int j=1;
    while(j!=i)
    {
        p=p->next;
        j++;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;

}




int main()
{
    node* head=(node*)malloc(sizeof(node));

    head=creatlink(head,10);
    print(head);

    finddata(head,4);

    deletelink(head,4);
    print(head);

    return 0;
}




#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;	 
	struct NODE *next;
};
typedef struct NODE node;
node *creat();
void print1(node *head);
void print2(node *head);
void sort1(node*head);/*选择排序*/
void sort2(node*head);/*插入排序*/
//void sort3(node*head);/*简单排序*/
void sort4(node*head);/*冒泡排序*/
int main()
{
 	node *head; 
 	
 	head=creat();             /*创建链表*/
 	
 	
 	printf("选择排序如下\n") ;
 	
 	sort1(head);         /*选择排序及两种输出*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	
 	
 	printf("插入排序如下\n") ;
 	
 	sort2(head);         /*插入排序及两种输出*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	
 	
 	printf("简单排序如下\n") ;
 	
 	sort3(head);         /*简单排序及两种输出*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	
 	
 	printf("冒泡排序如下\n") ;
 	
 	sort4(head);         /*冒泡排序及两种输出*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	return 0;
}
 
node *creat(){                                /*创造链表*/ 
	node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node *p1=head;
    int num=0;
    scanf("%d",&num);
    while(num!=-1){
    	node* p2;
    	p2=(node*)malloc(sizeof(node));
    	p2->next=NULL;
    	p2->data=num;
    	p1->next=p2;
    	scanf("%d",&num);
    	p1=p2;
	}
 	return head; 
}
 
 
void print1(node *head){                        /*尾部无特殊操作*/
	node *p;
 	p=head->next; 
 	do
 	{
 		printf("%d  ",p->data ); 
 		p=p->next ;	  			
	}while(p!=NULL);	
}


void print2(node *head){                       /*尾部特殊操作*/ 
	node* p=head->next;
	while(p->next!=NULL){
		printf("%d  ",p->data);
		p=p->next;
	} 
	printf("%d\n",p->data);
}


void sort1(node* head){                            /*选择排序*/
	node* pre = head;
	node* p = pre->next;
	node* bmin = pre;
	node* min;
	node* lmin;
	node* bq;
	node* q; 
	while (p->next){
		min = p;
		lmin = min->next;
		bq = p;
		q = p->next;
		while (q){
			if (q->data < min->data){	
				bmin = bq;
				min = q;
				lmin = min->next;
			}
			bq = q;
			q = q->next;
		}
		if (p->data != min->data){
			if (p->next == min){
				pre->next = min;
				p->next = lmin;
				min->next = p;
			}
			else{
				pre->next = min;
				min->next = p->next;
				p->next = lmin;
				bmin->next = p;
			}
		}
		pre = pre->next;
		p = pre->next;
	}
}


void sort2(node*head){                      /*插入排序*/ 
	node* zl=head;
	 node* qzj=head->next->next; 
	 node* preqzj=head->next;
	 node* prezl=NULL;
	 while(qzj->next!=NULL){
	 	while(zl->next!=qzj){
	 		if(zl->next->data > qzj->data){
	 			node* afqzj=qzj->next;
	 			qzj->next=zl->next;
	 			zl->next=qzj;
	 			preqzj->next=afqzj;
	 			break;
			}
	 		prezl=zl;
	 		zl=zl->next;
		}
	 	preqzj=qzj;
	 	qzj=qzj->next;
	 	zl=head;
	 	prezl=NULL;
	}
}

void sort4(node*head){                      /*冒泡排序交换值*/
	int num=0;
	node* p=head->next;
	node* t=head->next;  /*用t控制循环次数*/
	for(t=head->next;t->next!=NULL;t=t->next){
    	for(p=head->next;p->next!=NULL;p=p->next) {
	    	if( p->data > p->next->data ){
		    	num=p->next->data;
		    	p->next->data=p->data;
		    	p->data=num;
	    	}
    	}
    }
}

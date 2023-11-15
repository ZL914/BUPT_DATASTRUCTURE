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
void sort1(node*head);/*ѡ������*/
void sort2(node*head);/*��������*/
//void sort3(node*head);/*������*/
void sort4(node*head);/*ð������*/
int main()
{
 	node *head; 
 	
 	head=creat();             /*��������*/
 	
 	
 	printf("ѡ����������\n") ;
 	
 	sort1(head);         /*ѡ�������������*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	
 	
 	printf("������������\n") ;
 	
 	sort2(head);         /*���������������*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	
 	
 	printf("����������\n") ;
 	
 	sort3(head);         /*�������������*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	
 	
 	printf("ð����������\n") ;
 	
 	sort4(head);         /*ð�������������*/
 	
 	print1(head);
 	
 	printf("\n");
 	
 	print2(head);
 	
 	return 0;
}
 
node *creat(){                                /*��������*/ 
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
 
 
void print1(node *head){                        /*β�����������*/
	node *p;
 	p=head->next; 
 	do
 	{
 		printf("%d  ",p->data ); 
 		p=p->next ;	  			
	}while(p!=NULL);	
}


void print2(node *head){                       /*β���������*/ 
	node* p=head->next;
	while(p->next!=NULL){
		printf("%d  ",p->data);
		p=p->next;
	} 
	printf("%d\n",p->data);
}


void sort1(node* head){                            /*ѡ������*/
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


void sort2(node*head){                      /*��������*/ 
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

void sort4(node*head){                      /*ð�����򽻻�ֵ*/
	int num=0;
	node* p=head->next;
	node* t=head->next;  /*��t����ѭ������*/
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

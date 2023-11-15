#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;	 
	struct NODE *next;
};
typedef struct NODE node;

node *creat();//创造链表
void destoryList(node *zl);//释放链表空间
int pp(node*pa,node*pb );//判断是否为子序列

int main(){
	node*  headA;
	
	headA=(node*)malloc(sizeof(node));
	
	node*  headB;
	
	headB=(node*)malloc(sizeof(node));
	
	headA=creat();
	
	headB=creat();
	
	if(pp(headA,headB)==0){
		printf("ListB is not the sub sequence of ListA.");
    }
	else{
		printf("ListB is the sub sequence of ListA.");
    }
    destoryList(headA);
    destoryList(headB);
	return 0;
}


node *creat(){                             
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


void destoryList(node *zl){
	node* qzj;
	while(zl!=NULL){
		qzj=zl;
		zl=zl->next;
		free(qzj);
	}
}


int pp(node*pa,node*pb ){
	int mark=0;
	node* pA=pa->next;
	node* pB=pb->next;
	node* pam=pa->next;
	int num=pB->data;
	while(pA!=NULL&&mark==0){
		pB=pb->next;
		if(pA->data==num){
			pam=pA;
		    while(pB!=NULL&&pam!=NULL){
		    	if(pam->data!=pB->data){
		    		break;
				}
				if(pam!=NULL){
					pam=pam->next;
				}
				
				pB=pB->next;
			}
			if(pB==NULL){
				mark=1;
			}	
		}
		pA=pA->next;
	}
	return mark;
}


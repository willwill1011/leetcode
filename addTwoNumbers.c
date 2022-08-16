#include <stdio.h>
#include <stdlib.h>
// define
typedef struct listNode  // 
{   int val;    struct listNode * next; }Node;

// function
Node* createAndInsertNode(Node* head, int value){
    Node* current;
    current=head;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val=value;
    temp->next=NULL;
    if(head==NULL) { head=temp;}
    else{
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
    }
    return head;
}
void printLinkList(Node* lk){
    while(lk->next!=NULL){
        printf("%d-", lk->val);
        lk=lk->next;
        if(lk->next==NULL) { printf("%d\n", lk->val);}
    }
}
int lenLinkedList(Node* lk){
    int len=0;
    while(lk->next!=NULL){
        lk=lk->next;
        len++;
    }
    return ++len;
}

int main(){
#if 0   // good example
    Node* l1 = (Node*)malloc(sizeof(Node));
    Node* l2 = (Node*)malloc(sizeof(Node));
    Node* l3 = (Node*)malloc(sizeof(Node));
    Node* head = l1;
    l1->val=1;
    l1->next=l2;
    l2->val=2;
    l2->next=l3;
    l3->val=3;
    l3->next=NULL;
    while(head!=NULL){
        //printf("%d\n", head->val);
        head=head->next;
    }
#endif
#if 0   // good example
    lk1=createAndInsertNode(lk1, 9);
    lk1=createAndInsertNode(lk1, 8);
    lk1=createAndInsertNode(lk1, 7);
    while(lk1->next!=NULL){
        printf("%d-", lk1->val);
        lk1=lk1->next;
        if(lk1->next==NULL) { printf("%d", lk1->val);}
    }
#endif
    // linked list l1: 9-8-7
    // linked list l1: 1-2-3
    Node* lk1=NULL;
    Node* lk2=NULL;
    int i;
    for(i=0;i<6;i++){ lk1=createAndInsertNode(lk1, 9-i); }
    printLinkList(lk1);
    for(i=0;i<3;i++){ lk2=createAndInsertNode(lk2, i+1); }
    printLinkList(lk2);
    // 9-8-7 + 1-2-3 = 789+321 = 1110
    // check length of linked list
    int lenlk1, lenlk2;
    lenlk1=lenLinkedList(lk1);
    lenlk2=lenLinkedList(lk2);
    printf("lenlk1=%d lenlk2=%d\n", lenlk1, lenlk2);
    // for loop for max len of lk1 and lk2
    int lenMax=0;
    if(lenlk1>lenlk2){ lenMax=lenlk1; }
    else{ lenMax=lenlk2;}
    int carry=0;
    int temp=0;
    int l1, l2;
    Node* lk3=NULL;
    for(i=0;i<lenMax;i++){
        while((lk1!=NULL)||(lk2!=NULL)){
            l1=(lk1==NULL)?0:lk1->val;
            l2=(lk2==NULL)?0:lk2->val;
            temp=l1+l2;
            lk3=createAndInsertNode(lk3, (temp+carry)%10);
            carry=(temp>9)?1:0;
            if(lk1!=NULL){ lk1=(lk1->next==NULL)?NULL:lk1->next; }
            if(lk2!=NULL){ lk2=(lk2->next==NULL)?NULL:lk2->next; }
            printf("temp=%d l1=%d l2=%d carry=%d\n", temp, l1, l2, carry);
        }
    }
    if(carry==1){
        lk3=createAndInsertNode(lk3, carry);
    }
    printLinkList(lk3);
    return 0;
}
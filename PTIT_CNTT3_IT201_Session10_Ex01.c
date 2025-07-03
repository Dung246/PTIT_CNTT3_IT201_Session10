#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
//Tạo node
Node* createNode(int value){
    Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
      printf("Khong the cap phat bo nho");
      exit(0);
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
//In danh sách
void printList(Node*head){
    Node*current=head;
    while(current!= NULL){
        printf("%d -> ",current-> data);
        current=current-> next;
    }
    printf("NULL\n");
}
//giải phóng bộ nhows
void freeList(Node*head){
    Node* temp;
    while(head != NULL){
       temp=head;
       head=head-> next;
       free(temp);
    }
}

int main(){
    Node* head = NULL;
    head=createNode(2);
    head->next=createNode(3);
    head->next->next=createNode(5);
    head->next->next->next=createNode(7);
    head->next->next->next->next=createNode(9);
    //In danh sách
    printf("Danh sach lien ket don: ");
    printList(head);
    // Giải phóng bộ nhớ
    freeList(head);
    return 0;
}
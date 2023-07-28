#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list * next;
}list;

list * create(){
    list * head=NULL;
    int n;
    do{
        scanf("%d",&n);
        if(n==-1)
            break;
        if(head==NULL){
            head=(list*)malloc(sizeof(list));
            head->data=n;
            head->next=NULL;
        }
        else{
            list * temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=(list*)malloc(sizeof(list));
            temp=temp->next;
            temp->data=n;
            temp->next=NULL;
        }

    }while(1);
    return head;
}

void traverse(list *head){
    if(head==NULL){
        printf("List Is Empty.\n");return;
    }
    list *temp=head;
    while(temp!=NULL){
        printf("|%d",temp->data);
        temp=temp->next;
    }
    printf("|\n");
}

void insertion(list **head){
    if(*head==NULL){
        printf("Create Linked List first.\n");
        return;
    }
    printf("Enter position :");
    int position;scanf("%d",&position);
    int data;printf("Enter an integer to be inserted: ");scanf("%d",&data);
    if(position==1){
        list *temp=(list*)malloc(sizeof(list));
        temp->data=data;
        temp->next=*head;
        *head=temp;
    }
    else{
        list* temp=*head;
        while(position>2){
            position--;
            temp=temp->next;
        }
        list* temp1=(list*)malloc(sizeof(list));
        temp1->data=data;
        temp1->next=temp->next;
        temp->next=temp1;
    }
}

void deletion(list** head){
    if(head==NULL){
        printf("kya delete karuuu.Kuch nahi hai List meee.\n");
        return;
    }
    printf("Enter position :");
    int position;scanf("%d",&position);
    if(position==1){
        list* temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    else{
        list* temp=*head;
        while(position>2){
            position--;
            temp=temp->next;
        }
        list *temp1=temp->next;
        temp->next=temp->next->next;
        free(temp1);
    }

}

void insert_after(list** head){
    if(*head==NULL){
        printf("Create Linked List first.\n");
        return;
    }
    int n,value;printf("Enter an integer to be inserted: ");scanf("%d",&n);
    printf("Enter a value after which u have to insert: ");scanf("%d",&value);
    list* temp=*head;
    while(temp!=NULL){
        if(temp->data==value){
            list* temp1=(list*)malloc(sizeof(list));
            temp1->data=n;
            temp1->next=temp->next;
            temp->next=temp1;
            if(temp->next!=NULL)
            temp=temp->next;
        }
        temp=temp->next;
    }
}

void deletion_particular(list** head){
    if(head==NULL){
        printf("kya delete karuuu.Kuch nahi hai List meee.\n");
        return;
    }
    int value;printf("Enter an integer to be deleted: ");scanf("%d",&value);
    list* temp=*head;
    while(temp->next!=NULL){
        if(temp->next->data==value){
            list* temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
        }
        else
            temp=temp->next;
    }
    if((*head)->data==value){
        list* temp=*head;
        *head=temp->next;
        free(temp);
    }
}

void LINKEDLIST(){
    list* head=create();
    traverse(head);
    insert_after(&head);
    traverse(head);
    deletion_particular(&head);
    traverse(head);
    insertion(&head);
    traverse(head);
    deletion(&head);
    traverse(head);
}

int main(){
    LINKEDLIST();
}
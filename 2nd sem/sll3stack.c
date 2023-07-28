#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct s{
    int n;struct s* next;
};

void input(struct s* head){
    printf("Enter a integer: ");scanf("%d",&(head->n));
    printf("--------------------------------------\n");

}

void output(struct s* t){
    if(t==NULL){
        printf("STACK IS EMPTY!!!\n");return;
    }
    printf("\nCURRENT STACK IS :\n|");
    while(t!=NULL){
        printf(" %d |",t->n);
        t=t->next;
    }
    printf("\n");
}


int isfull(struct s* head){
    head=malloc(sizeof(struct s));
    if(head==NULL)
        return 1;
    return 0;
}

int isempty(struct s* head){
    if(head==NULL){
        return 1;
    }
    return 0;
}

void push(struct s** head){
    if(isfull(*head)){
        printf("STACK IS FULL.\n");return;
    }
    if(isempty(*head)){printf("STACK Doesn't Exists.\nUSE create().\n");return;}
    struct s* t=malloc(sizeof(struct s));
    input(t);
    t->next=*head;
    *head=t;
}
    
void pop(struct s**head){
    if(isempty(*head)){
        printf("STACK is already empty.\n");return;
    }
    printf("Deleted Element is: %d\n",(*head)->n);
    if((*head)->next==NULL){
        *head=NULL;return;
    }
    struct s* t=*head;
    *head=(*head)->next;
    free(t);
}

void create(struct s** head){
    if(*head!=NULL){
        printf("STACK already exists.\nUSE push() operation.\n");
    }
    else{
        *head=malloc(sizeof(struct s));(*head)->next=NULL;
        int n;printf("Enter no of node: ");scanf("%d",&n);
        printf("______________________________________\n");
        n--;input(*head);
        while(n--){
            push(head);
        }
    }
}

int main(){
    int n;
    struct s* head=NULL;
    do{
        printf("Various Stack Operations are :\n0.Stop\n1.Create()\n2.IsEmpty()\n3.Push()\n4.Pop()\n5.IsFull()\n6.Display\n-> ");
        scanf("%d",&n);
        switch(n){
            case 1:
                create(&head);break;
            case 2:
                if(isempty(head)==1)
                    printf("STACK is Empty.\n");
                else
                    printf("STACK is Not Empty.\n");
                break;
            case 3:
                push(&head);break;
            case 4:
                pop(&head);break;
            case 5:
                isfull(head);
                if(isfull(head))
                    printf("STACK is Full.\n");
                else
                    printf("STACK is not Full.\n");
                break;
            case 6:
                output(head);break;
            default:
                if(n!=0){printf("Invalid option\n");}
        }
    }while(n);
    printf("TAATAA!!");
    getch();
}
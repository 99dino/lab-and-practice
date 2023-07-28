#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct s{
    int n;struct s*next;
};

void input(struct s* head){
    printf("Enter a integer: ");scanf("%d",&(head->n));
    printf("--------------------------------------\n");

}

void output(struct s* t){
    if(t==NULL){
        printf("QUEUE IS EMPTY!!!\n");return;
    }
    printf("\nCURRENT QUEUE IS :\n|");
    while(t!=NULL){
        printf(" %d |",t->n);
        t=t->next;
    }
    printf("\n");
    
}

void create(struct s** head){
    if(*head!=NULL){
        printf("QUEUE already exists.\nUSE Enqueue() operation.\n");
    }
    else{
        *head=malloc(sizeof(struct s));
        struct s*t;t=*head;
        int n;printf("Enter no of node: ");scanf("%d",&n);
        printf("______________________________________\n");
        while(n--){
            input(t);
            struct s *x=malloc(sizeof(struct s));
            if(n!=0){t->next=x;t=x;}
        }
        t->next=NULL;
    }
}

int isfull(struct s* head){
    head=malloc(sizeof(struct s));
    if(head==NULL)
        return 1;
    return 0;
}

int isempty(struct s* head){
    if(head==NULL)
        return 1;
    return 0;
}

void dequeue(struct s**head){
    if(isempty(*head)){
        printf("QUEUE IS ALREADY EMPTY.\n");return;
    }
    struct s* t=*head;
    *head=(*head)->next;free(t);
}

void enqueue(struct s* head){
    if(isfull(head)){
        printf("QUEUE IS FULL.\n");return;
    }
    if(isempty(head)){printf("QUEUE Doesn't Exists.\nUSE create().\n");return;}
    
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=malloc(sizeof(struct s));
    input(head->next);
    head->next->next=NULL;
}

int main(){
    int n;
    struct s* head=NULL;
    do{
        printf("Various Queue Operations are :\n0.Stop\n1.Create()\n2.IsEmpty()\n3.Enqueue\n4.Dequeue\n5.IsFull()\n6.Display\n-> ");
        scanf("%d",&n);
        switch(n){
            case 1:
                create(&head);break;
            case 2:
                if(isempty(head)==1)
                    printf("QUEUE is Empty.\n");
                else
                    printf("QUEUE is Not Empty.\n");
                break;
            case 3:
                enqueue(head);break;
            case 4:
                dequeue(&head);break;
            case 5:
                isfull(head);
                if(isfull(head))
                    printf("QUEUE is Full.\n");
                else
                    printf("QUEUE is not Full.\n");
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
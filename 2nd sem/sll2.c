#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct s{
    char a[100];struct s *next;
};

void output(struct s* t){
    if(t==NULL){
        printf("LINKED LIST IS EMPTY!!!\n");return;
    }
    printf("\nCURRENT LINKED LIST IS :\n");
    printf("______________________________________\n");
    while(t!=NULL){
        printf("%s\n",t->a);
        printf("--------------------------------------\n");
        t=t->next;
    }
}

void input(struct s* head){
    printf("Enter a string :");scanf("%s",head->a);
    printf("--------------------------------------\n");

}

//function to create n no. of nodes from the given head
void node_create(int n,struct s* head){
    printf("______________________________________\n");
    while(n--){
        input(head);
        struct s *x=malloc(sizeof(struct s));
        if(n!=0){head->next=x;head=x;}
    }
    head->next=NULL;
}

//function to reverse linked list
void rev(struct s **head){
    struct s* t=*head,*a=*head;
    t=t->next;
    while(t->next!=NULL){
        struct s*y=t->next;
        t->next=a;
        a=t;
        t=y;
    }
    t->next=a;
    (*head)->next=NULL;
    *head=t;
}

//function to swap values in pairs
void pair_swap(struct s* head){
    while(head!=NULL){
        if(head->next!=NULL){
            char st[100];
            strcpy(st,head->a);
            strcpy(head->a,head->next->a);
            strcpy(head->next->a,st);
            head=head->next->next;
        }
        else
            head=head->next;
    }
}

int main(){
    //taking no of nodes to create from user
    int n,x;
    printf("enter no of node : ");scanf("%d",&n);
    //creating Linked List of n node
    struct s *head=malloc(sizeof(struct s)),*t;
    node_create(n,head);t=head;
    //displaying the Linked List after creating
    output(head);
    //calling fucntion to reverse the Linked List
    rev(&head);
    printf("After reversing the linked list\n");
    output(head);
    //calling function to swap consecutive members
    pair_swap(head);
    printf("After swapping consecutive members\n");
    output(head);
    getch();
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct s{
    int n;struct s* next;
};

void input(struct s* head){
    printf("Enter a integer :");scanf("%d",&head->n);
    printf("--------------------------------------\n");

}

void output(struct s* t){
    if(t==NULL){
        printf("LINKED LIST IS EMPTY!!!\n");return;
    }
    while(t!=NULL){
        printf("%d",t->n);
        t=t->next;
    }
}

void node_create(struct s* head){
    int n;printf("\nEnter no of node: ");scanf("%d",&n);
    printf("______________________________________\n");
    while(n--){
        input(head);
        struct s *x=malloc(sizeof(struct s));
        if(n!=0){head->next=x;head=x;}
    }
    head->next=NULL;
}

void conc(struct s* head1,struct s* head2,struct s** head3){
    struct s* t;
    int f=1;
    while(head1!=NULL){
        if((head1->n)%2==0){
            if(f){
                *head3=malloc(sizeof(struct s));
                (*head3)->n=head1->n;t=*head3;f=0;
            }
            else{
                t->next=malloc(sizeof(struct s));
                t=t->next;t->n=head1->n;
            }
        }
        head1=head1->next;

    }
    while(head2!=NULL){
        if((head2->n)%2==0){
            if(f){
                *head3=malloc(sizeof(struct s));
                (*head3)->n=head2->n;t=*head3;f=0;
            }
            else{
                t->next=malloc(sizeof(struct s));
                t=t->next;t->n=head2->n;
            }
        }
        head2=head2->next;
    }
    if(f==0)
        t->next=NULL;
}

int main(){
    struct s* head1=malloc(sizeof(struct s)),* head2=malloc(sizeof(struct s)),*head3=NULL;
    node_create(head1);
    node_create(head2);
    conc(head1,head2,&head3);
    printf("After concatenating: ");
    //printed in concatenated form but stored in a Linked List
    output(head3);
    getch();
}
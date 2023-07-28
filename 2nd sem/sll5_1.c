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
    printf("CURRENT LINKED LIST IS :\n|");
    while(t!=NULL){
        printf(" %d |",t->n);
        t=t->next;
    }
    printf("\n\n");
    
}

void node_create(struct s* head){
    int n;printf("Enter no of node: ");scanf("%d",&n);
    printf("______________________________________\n");
    while(n--){
        input(head);
        struct s *x=malloc(sizeof(struct s));
        if(n!=0){head->next=x;head=x;}
    }
    head->next=NULL;
}

int size(struct s* head){
    int n=0;
    while(head!=NULL){
        head=head->next;n++;
    }
    return n;
}

void sort(struct s* head){
    struct s *t=head;
    int n=size(head);
    for(int i=n-2;i>=0;i--){
        t=head;
        for(int j=0;j<=i;j++){
            if(t->n>t->next->n){
                int x=t->n;
                t->n=t->next->n;
                t->next->n=x;
            }
            t=t->next;
        }
    }
}

int main(){
    struct s* head=malloc(sizeof(struct s));
    node_create(head);
    output(head);
    sort(head);
    printf("After Sorting:\n");
    output(head);
    getch();
}
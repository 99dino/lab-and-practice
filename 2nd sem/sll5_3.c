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
    printf("\nCURRENT LINKED LIST IS :\n|");
    while(t!=NULL){
        printf(" %d |",t->n);
        t=t->next;
    }
    printf("\n");
    
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

void find(struct s* head){
    int a[10000]={0};
    struct s* t=head,*tt;
    while(t!=NULL){
        int s=0;
        tt=head;
        if(a[t->n]==0){
            while(tt!=NULL){
                if(tt->n==t->n)
                s++;
                tt=tt->next;
            }
            printf("%d occured %d times.\n",t->n,s);a[t->n]=1;
        }
        t=t->next;
    }
}

int main(){
    struct s* head=malloc(sizeof(struct s));
    node_create(head);
    find(head);
    getch();
}
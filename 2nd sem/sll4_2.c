#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct s{
    int co,ex;struct s *next;
};

void input(struct s* head){
    printf("Enter coeffecient :");scanf("%d",&head->co);
    printf("Enter exponent :");scanf("%d",&head->ex);
    printf("--------------------------------------\n");

}

void output(struct s* t){
    // printf("--------------------------------------\n");
    while(t!=NULL){
        printf("%s%dx^%d",(t->co>0?" +":" "),t->co,t->ex);
        t=t->next;
    }
    printf("\n--------------------------------------\n");
}

void poly(struct s** head){
    *head=malloc(sizeof(struct s));
    struct s*t;t=*head;
    int n;printf("Enter no of terms in a polynomial: ");scanf("%d",&n);
    printf("Enter polynomial in decreasing power\n");
    printf("______________________________________\n");
    while(n--){
        input(t);
        if(n!=0){t->next=malloc(sizeof(struct s));t=t->next;}
    }
    t->next=NULL;
}
void compare(struct s* p1,struct s* p2){
    while(p1!=NULL&&p2!=NULL){
        if(p1->co!=p2->co||p1->ex!=p2->ex){
            printf("Polynomial 1 and 2 are not EQUAl.\n");return;
        }
        p1=p1->next;
        p2=p2->next;
    }
    if(p1!=p2)
        printf("Polynomial 1 and 2 are not EQUAl.\n");
    else
        printf("Polynomial 1 and 2 are EQUAl.\n");
}

int main(){
    struct s* poly1=NULL,*poly2=NULL;
    poly(&poly1),poly(&poly2);
    printf("POLYNOMIAL 1 : ");output(poly1);
    printf("POLYNOMIAL 2 : ");output(poly2);
    compare(poly1,poly2);
    getch();
}
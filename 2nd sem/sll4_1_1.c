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
            if(t->ex<t->next->ex){
                int x=t->ex,y=t->co;
                t->ex=t->next->ex,t->next->ex=x;
                t->co=t->next->co,t->next->co=y;
            }
            t=t->next;
        }
    }
}

void add(struct s** p){
    struct s* p3=malloc(sizeof(struct s)),*pp;pp=p3;int f=1;
    pp->co=(*p)->co;
    pp->ex=(*p)->ex;
    (*p)=(*p)->next;
    while(*p!=NULL){
        if(pp->ex==(*p)->ex){
            pp->co+=(*p)->co;
        }
        else{
            pp->next=malloc(sizeof(struct s));
            pp=pp->next;
            pp->co=(*p)->co;
            pp->ex=(*p)->ex;
        }
        (*p)=(*p)->next;
    }
    pp->next=NULL;
    *p=p3;
}

struct s* multipoly(struct s* p1,struct s* p2){
    struct s* p3=malloc(sizeof(struct s)),*p;p=p3;int f=1;
    while(p1){
        struct s* t=p2;
        while(t){
            if(f){
                p->co=p1->co*t->co;
                p->ex=p1->ex+t->ex;f=0;
            }
            else{
                struct s* x=malloc(sizeof(struct s));
                x->co=p1->co*t->co;
                x->ex=p1->ex+t->ex;
                p->next=x;p=x;
            }
            t=t->next;
        }
        p1=p1->next;
    }
    p->next=NULL;
    sort(p3);
    add(&p3);
    return p3;
}

int main(){
    struct s* poly1=NULL,*poly2=NULL,*poly3=NULL;
    poly(&poly1),poly(&poly2);
    printf("POLYNOMIAL 1 : ");output(poly1);
    printf("POLYNOMIAL 2 : ");output(poly2);

    poly3=multipoly(poly1,poly2);
    printf("MULTIPLYING POLYNOMIAL 1 & POLYNOMIAL 2 : ");output(poly3);
    getch();
}
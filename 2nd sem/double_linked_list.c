#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct s{
    struct s* prev;
    int i;
    struct s* next;
};

void input(struct s* head){
    printf("Enter a integer :");scanf("%d",&head->i);
    printf("--------------------------------------\n");

}

void create(struct s** head,struct s** tail,int *x){
    int n;printf("no of node?");
    scanf("%d",&n);
    if(n==0){
        return;
    }
    *x=n;
    *head=malloc(sizeof(struct s));
    struct s* t=*head,*p=NULL;
    // (*head)->prev=NULL;
    while(n--){
        input(t);
        t->prev=p;
        p=t;
        if(n!=0){
            t->next=malloc(sizeof(struct s));
            t=t->next;
        }
    }
    *tail=t;
    t->next=NULL;
}

void outputh(struct s* head){
    if(head!=NULL){
        printf("LINKED LIST IS EMPTY!!\n");return;
    }
    while(head!=NULL){
        printf("%d ",head->i);
        head=head->next;
    }
    printf("\n");
}

void outputt(struct s* tail){
    while(tail!=NULL){
        printf("%d ",tail->i);
        tail=tail->prev;
    }
    printf("\n");
}

void ins_begh(struct s** head){
    (*head)->prev=malloc(sizeof(struct s));
    (*head)->prev->next=*head;
    *head=(*head)->prev;
    input(*head);
    (*head)->prev=NULL;

}

// void ins_begt(struct s* tail){
//     while((tail)->prev!=NULL){
//         tail=(tail)->prev;
//     }
//     (tail)->prev=malloc(sizeof(struct s));
//     (tail)->prev->next=tail;
//     tail=(tail)->prev;
//     input(tail);
//     tail->prev=NULL;
// }

void ins_endt(struct s** tail){
    (*tail)->next=malloc(sizeof(struct s));
    (*tail)->next->prev=*tail;
    *tail=(*tail)->next;
    input(*tail);
    (*tail)->next=NULL;
}

void ins_endh(struct s* head){
    while((head)->next!=NULL){
        head=(head)->next;
    }
    (head)->next=malloc(sizeof(struct s));
    head->next->prev=head;
    head=head->next;
    head->next=NULL;
    input(head);
}

void ins_posh(struct s** head,int n){
    int a;printf("enter postion where u wanna enter: ");scanf("%d",&a);
    if(a<1||a>n+1){
        printf("INVALID POSITION!!!\n");return;
    }
    if(a==1){
        ins_begh(head);
    }
    else if(a==n+1){
        ins_endh(*head);
    }
    else{
        a-=2;
        struct s* t=*head,*p=malloc(sizeof(struct s));
        while(a--){
            t=t->next;
        }
        input(p);
        p->prev=t;
        p->next=t->next;
        t->next=p;
    }
}

void del_begh(struct s** head){
    *head=(*head)->next;
    free((*head)->prev);
    (*head)->prev=NULL;
}

void del_endt(struct s** tail){
    *tail=(*tail)->prev;
    free((*tail)->next);
    (*tail)->next=NULL;
}

void del_pos(struct s** head,int *n){
    int a;printf("enter postion of node u wanna delete: ");scanf("%d",&a);
    if(a<1||a>*n){
        printf("INVALID POSITION!!!\n");return;
    }
    struct s* p=*head,*t;
    if(a==1){
        del_begh(head);
    }
    else if(a==*n){
        while(p->next!=NULL){
            p=p->next;
        }
        del_endt(&p);
    }
    else{
        a-=1;
        while(a--){p=p->next;}
        t=p;
        t->next->prev=t->prev;
        t->prev->next=t->next;
        free(t);
    }
}

int main(){
    struct s* head=NULL,*tail=NULL;int n=0;
    create(&head,&tail,&n);
    printf("DISPLAYING using head pointer: \n");
    outputh(head);
    // printf("DISPLAYING using tail pointer: \n");
    // outputt(tail);
    // ins_begh(&head);n++;
    // printf("DISPLAYING after inserting at the begining using head pointer: \n");
    // outputh(head);
    // ins_begt(tail);
    // outputt(tail);
    // ins_endt(&tail);n++;
    // printf("DISPLAYING after inserting at the end using head pointer: \n");
    // outputh(head);
    // printf("DISPLAYING after inserting at the end using tail pointer: \n");
    // outputt(tail);
    // ins_posh(&head,n);n++;
    // printf("DISPLAYING after inserting at the given position using head pointer: \n");
    // outputh(head);
    // del_begh(&head);
    // printf("DISPLAYING after deleting from the begining using head pointer: \n");
    // outputh(head);
    // del_endt(&tail);
    // printf("DISPLAYING after deleting from the end using tail pointer: \n");
    // outputt(tail);
    del_pos(&head,&n);
    outputh(head);
    return 0;
}
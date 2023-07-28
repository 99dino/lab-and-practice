#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct s{
    char a[100];struct s *next;
};

void output(struct s* t){
    if(t==NULL){
        printf("LINKED LIST IS EMPTY!!!\n\n");return;
    }
    printf("CURRENT LINKED LIST IS :\n");
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

//function to add a node at the begining
void add_beg(struct s** head){
    struct s* t=malloc(sizeof(struct s));
    input(t);
    t->next=*head;
    *head=t;
}

// function to add a node at the end
void add_end(struct s *head){
    while(head->next!=NULL){
        head=head->next;
    }
    struct s* t=malloc(sizeof(struct s));
    input(t);
    head->next=t;
    t->next=NULL;
}

//function at add a node at certain position
void add_pos(int a,int n,struct s** head){
    //if first position then add in begining
    if(a<1||a>n+1){
        printf("INVALID POSITION!!!\n");return;
    }
    if(a==1)
        add_beg(head);
    //if last position then add at the end
    else if(a==n+1)
        add_end(*head);
    else{
        a-=2;struct s *h=*head;
        while(a--){
            h=(h)->next;
        }
        struct s* t=malloc(sizeof(struct s));
        input(t);
        t->next=(h)->next;
        (h)->next=t;
    }
}

// funcion to completely delete the linked list
void delete(struct s** head){
    while((*head)!=NULL){
        struct s* t=(*head);
        *head=(*head)->next;free(t);
    }
}

// function to remove a node with particular key value
void del(struct s ** head,char key[],int *n){
    struct s* x=NULL,*t=*head,*tt;int q=0;
    while(t!=NULL){
        if(strcmp(t->a,key)){
            q++,(*n)--;
            if(q==1){
                x=malloc(sizeof(struct s));tt=x;
                strcpy(tt->a,t->a);
            }
            else{
                tt->next=malloc(sizeof(struct s));
                tt=tt->next;
                strcpy(tt->a,t->a);tt->next=NULL;
            }
        }
        t=t->next;
    }
    tt->next=NULL;
    delete(head);
    *head=x;
}

// function to copy the linked list
struct s* copying(struct s*head){
    printf("AFTER COPYING LINKED LIST:\n");
    if(head==NULL)
    return NULL;
    struct s* copied=malloc(sizeof(struct s)),*p;p=copied;
    while(head!=NULL){
        strcpy(p->a,head->a);
        p->next=malloc(sizeof(struct s));
        if(head->next!=NULL){
            p=p->next;
        }
        head=head->next;
    }
    p->next=NULL;
    return copied;
}

// fucntion to access nth node from header
void acc_node(struct s* head,char key[]){
    int n=1,f=0;
    while(head!=NULL){
        if(strcmp(head->a,key)==0){
            printf("Element found at %dth node.\n",n);return;
        }
        n++;head=head->next;
    }
    printf("STRING NOT FOUND!!!\n");
}

int main(){
    //taking no of nodes to create
    int n,x;
    printf("enter no of node : ");scanf("%d",&n);
    //creating Linked List of n node
    struct s *head=malloc(sizeof(struct s)),*t;
    node_create(n,head);t=head;
    //displaying the Linked List after creating
    output(head);
    printf("Enter position where u want to insert a node: ");scanf("%d",&x);
    add_pos(x,n,&head);
    output(head);
    char st[100];printf("Enter a string to find it's poisition wrt header: ");
    scanf("%s",st);
    acc_node(head,st);
    //taking a string to delete from current Linked List
    printf("Enter a string to delete from Linked List: ");scanf("%s",st);
    //calling del function to delete string given by user
    del(&head,st,&n);
    //displaying current Linked List after deletion
    output(head);
    //calling copying function and that return head pointer to duplicate Linked List
    struct s* copied=copying(head);
    //displaying copied Linked List
    output(copied);
    //calling function to completely delete copied Linked List
    delete(&copied);
    //displaying current Linked List
    printf("Copied linked list is now deleted:\n");
    output(copied);
    // original linked list is preserved
    printf("Original Linked List remain intact.\n");
    output(head);
    getch();
}
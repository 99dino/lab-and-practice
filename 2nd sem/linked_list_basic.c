#include<stdio.h>
#include<stdlib.h>

struct s{
    int i;char c;struct s *p;
};

void output(struct s* t){
    if(t==NULL){
        printf("LINKED LIST IS EMPTY!!!\n");
    }
    printf("\nCURRENT LINKED LIST IS :\n");
    while(t!=NULL){
        printf("INT : %d\n",t->i);
        printf("CHAR : %c\n",t->c);
        printf("--------------------------------------\n");
        t=t->p;
    }
}

void input(struct s* head){
    printf("\nEnter a integer :");
    scanf("%d",&head->i);
    printf("Enter a character :");
    scanf("\n%c",&head->c);
    printf("______________________________________\n");

}

//function to create n no. of nodes from the given head
void node_create(int n,struct s* head){
    printf("\n______________________________________\n");
 
    while(n--){
        input(head);
        struct s *x=malloc(sizeof(struct s));
        if(n!=0){head->p=x;head=x;}
    }
    head->p=NULL;
}

//function to create n no of nodes by creating head
// struct s* node_create(int n){
//     struct s*h=malloc(sizeof(struct s)),*t;t=h;
//     while(n--){
//         input(h);
//         struct s*x=malloc(sizeof(struct s));
//         if(n!=0){h->p=x;h=x;}
//     }
//     h->p=NULL;
//     return t;
// }

//function to add a node at the begining
void add_beg(struct s** head){
    struct s* t=malloc(sizeof(struct s));
    input(t);
    t->p=*head;
    *head=t;
}

// function to add a node at the end
void add_end(struct s *head){
    while(head->p!=NULL){
        head=head->p;
    }
    struct s* t=malloc(sizeof(struct s));
    input(t);
    head->p=t;
    t->p=NULL;
}

//function at add a node at certain position
void add_pos(int a,int n,struct s** head){
    if(a==1)
        add_beg(head);
    else if(a==n)
        add_end(*head);
    else{
        a-=2;struct s *h=*head;
        while(a--){
            h=(h)->p;
        }
        struct s* t=malloc(sizeof(struct s));
        input(t);
        t->p=(h)->p;
        (h)->p=t;
    }
}

// function to delete first node
void del_beg(struct s ** head){
    if((*head)->p==NULL){
        *head=NULL;return;
    }
    struct s* t=*head;
    *head=(*head)->p;
    free(t);
}

// function to delete last node
void del_end(struct s **head){
    struct s* temp=*head;
    if((*head)->p==NULL)
    *head=NULL;
    while(temp->p->p!=NULL){
        temp=temp->p;
    }
    struct s* t=temp->p;
    temp->p=NULL;
    free(t);
}

// function to delete node at certain position
void del_pos(int x,int n,struct s** head){
    struct s* t=*head;
    if(x==1){
        del_beg(head);
    }
    else if(x==n){
        del_end(head);
    }
    else{
        x-=2;
        while(x--){
            (*head)=(*head)->p;
        }
        t=(*head)->p;
        (*head)->p=t->p;
        free(t);
    }
}

// funcion to completely delete the linked list
void delete(struct s** head){
    while((*head)!=NULL){
        struct s* t=(*head);
        *head=(*head)->p;free(t);
    }
}

//function to reverse linked list
void rev(struct s **head){
    struct s* t=*head,*a=*head;
    t=t->p;
    while(t->p!=NULL){
        struct s*y=t->p;
        t->p=a;
        a=t;
        t=y;
    }
    // t->p=y;
    t->p=a;
    (*head)->p=NULL;
    *head=t;
}

//function to reverse without using auxiliary pointer
void reverse(struct s**head){
    int n=1;struct s* t=*head,*temp=*head;
    while(temp->p!=NULL){
        temp=temp->p;n++;
    }
    for(int i=n-2;i>=0;i--){
        t=*head;
        for(int j=0;j<i;j++){
            t=t->p;
        }
        t->p->p=t;
    }
    (*head)->p=NULL;
    *head=temp;
}

int main(){
    int n,x;
    printf("enter no of node : ");scanf("%d",&n);
    struct s *head=malloc(sizeof(struct s)),*t;
    node_create(n,head);t=head;
    output(head);
    
    reverse(&head);
    output(head);

    // printf("\nAdding a node at the end: \n");
    // add_end(head);n++;
    // output(head);
    
    // printf("\nAdding a node at the begining: \n");
    // add_beg(&head);n++;
    // output(head);
    
    // printf("Enter position where u wanna insert a node :");
    // scanf("%d",&x);n++;
    // add_pos(x,n,&head);
    // output(head);

    // printf("\nDeleting a node at the beg: \n");
    // del_beg(&head);n--;
    // output(head);

    // printf("\nDeleting a node at the end: \n");
    // del_end(&head);n--;
    // output(head);


    // printf("Enter position of node u wanna delete :");
    // scanf("%d",&x);
    // del_pos(x,n,&head);n--;
    // output(head);
    return 0;
}


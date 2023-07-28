#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 6          // no. of nodes

typedef struct gnode{
    int vertex;
    int weight; 
    struct gnode* next;
}gnode;
typedef struct graph{
    int predecessor;
    int pIndex;  //predecessor index
    int inPQ;    // as a flag to check if present in PQ(1) or not(0)
    int indexInPQ; // index in PQ
    gnode* arr; 
}graph;

// queue started
struct node
{
    int data;
    struct node *next;
};
struct node* createqueue(struct node* head)
{
    if(head==NULL)
    {
        head=(struct node*) malloc(sizeof(struct node));
        printf("Enter first element ?\n");
        int x;
        scanf("%d", &x);
        head->data=x;
        head->next=NULL;
    }
    else
    {
        printf("Queue is already present, Use Insert.\n");
    }
    return head;
}
int dequeue(struct node** head)
{
    int x;
    if ((*head)!=NULL)
    {
        x=(*head)->data;
        struct node* temp=(*head);
        (*head)=(*head)->next;
        free(temp);
        return x;
    }
    else
    {
        printf("Queue is Empty.\n");
        return -1;
    }
}
int isempty(struct node* head)
{
    if(head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node * enqueue(struct node* head, int x)
{
    struct node* temp=malloc(sizeof(struct node)), *t=head;
    temp->data=x;
    temp->next=NULL;
    if (head==NULL)
    {
        return temp;
    }
    
    while (head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
}
struct node* put(struct node* head, int x)
{
    struct node* temp=malloc(sizeof(struct node)), *t=head;
    temp->data=x;
    temp->next=NULL;
    if (head==NULL)
    {
        return temp;
    }
    temp->next=head;
    return temp;
}
void displaynode(struct node* ll)
{
    while (ll!=NULL)
    {
        printf("%d ", ll->data);
        ll=ll->next;
    }
}
//queue ended

int trav_status[N+1];
struct node* ll=NULL;
void Topo_Visit(graph g[], int i)
{
    trav_status[i]=1;
    gnode* temp=g[i].arr;
    while (temp!=NULL)
    {
        int j=temp->vertex;
        if(trav_status[j]==0)
        {
            Topo_Visit(g,j);
        }
        temp=temp->next;
    }
    ll=put(ll,i);
}
struct node* Topological_Sort(graph g[])
{
    for(int i=0; i<N+1; i++)
    {
        trav_status[i]=0;
    }
    for (int i = 1; i < N+1; i++)
    {
        if(trav_status[i]==0)
        {
            Topo_Visit(g,i);
        }
    }
    return ll;
}

void input(graph g[])
{
    for (int i = 0; i < N+1; i++)
    {
        g[i].arr=NULL;
    }
    printf("Enter the adjacent vertex for each vertex with weight : \n");
    for (int i = 1; i < N+1; i++)
    {
        printf("%d : ", i);
        int x=1,wt=0;
        while (x!=-1)
        {
            scanf("%d", &x);
            
            if(x==-1)
            break;
            scanf("%d", &wt);
            gnode *temp = malloc(sizeof(gnode));
            gnode *temp2 = g[i].arr;
            temp->vertex=x;
            temp->weight=wt;
            temp->next=NULL;
            if(temp2==NULL)
            {
                g[i].arr=temp;
            }
            else
            {
                if(temp2->vertex > temp->vertex)
                {
                    temp->next=temp2;
                    g[i].arr=temp;
                }
                else
                {
                    while (temp2->next!=NULL && temp2->next->vertex < temp->vertex)
                    {
                        temp2=temp2->next;
                    }
                    temp->next=temp2->next;
                    temp2->next=temp;
                }
            }
        }
    } 
}

void display(graph g[])
{
    for (int i = 0; i < N; i++)
    {
        gnode* temp = g[i].arr;
        printf("%d : ", i);
        while(temp!=NULL)
        {
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int visited[N+1];
int top;
struct node* topo_order;
void DAG(graph g[], int src)
{
    topo_order=Topological_Sort(g);
    int ans_Set[N+1];
    for (int i = 0; i < N+1; i++)
    {
        // ans_Set[i]=INT_MAX;
    }
    top=N;
    for (int i = 0; i < N+1; i++)
    {
        g[i].predecessor=-1;
        g[i].inPQ=1;
        g[i].pIndex=-1;
        g[i].indexInPQ=i;
    }
    while (topo_order->data!=src)
    {
        // ans_Set[topo_order->data]=INT_MIN;
        topo_order=topo_order->next;
    }
    ans_Set[src]=0;
    
    while(topo_order!=NULL)
    {
        int u=topo_order->data;
        gnode* temp=g[u].arr;
        while (temp!=NULL)
        {
            int v=temp->vertex;
            if(temp->weight+ans_Set[u] < ans_Set[v])
            {
                ans_Set[v]=temp->weight+ans_Set[u];
                g[v].predecessor=u;
            }
            temp=temp->next;
        }
        topo_order=topo_order->next;
    }
    for (int i = 1; i < N+1; i++)
    {
        printf("%d : %d    ", i, ans_Set[i]);
    }
    
}

int main()
{
    graph graph[N+1];
    input(graph);
    DAG(graph,1);
    return 0;
}


/*
2 5 3 3 -1
3 2 4 6 -1
4 7 5 4 6 2 -1
5 -2 6 1 -1
6 -2 -1
-1
*/
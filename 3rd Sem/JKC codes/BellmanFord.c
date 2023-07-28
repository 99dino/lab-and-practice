#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 5          // no. of nodes

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
void BellmanFord(graph g[], int src)
{
    int ans_Set[N+1];
    for (int i = 0; i < N+1; i++)
    {
        ans_Set[i]=-100000000;
    }
    top=N;
    for (int i = 0; i < N+1; i++)
    {
        g[i].predecessor=-1;
        g[i].inPQ=1;
        g[i].pIndex=-1;
        g[i].indexInPQ=i;
    }
    ans_Set[src]=0;
    
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N+1; j++)
        {
            gnode* temp=g[j].arr;
            while (temp!=NULL)
            {
                int v=temp->vertex;
                if(temp->weight+ans_Set[j] < ans_Set[v])
                {
                    ans_Set[v]=temp->weight+ans_Set[j];
                    g[v].predecessor=j;
                }
                temp=temp->next;
            }
        }
    }
    for (int j = 1; j < N+1; j++)
    {
        gnode* temp=g[j].arr;
        while (temp!=NULL)
        {
            int v=temp->vertex;
            if(temp->weight+ans_Set[j] < ans_Set[v])
            {
                printf("-ve cycle detected.");
                return;
            }
            temp=temp->next;
        }
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
    BellmanFord(graph,1);
    return 0;
}


/*
2 5 3 3 -1
3 2 4 6 -1
4 7 5 4 6 2 -1
5 -2 6 1 -1
6 -2 -1
-1

1 : 0    2 : 5    3 : 3    4 : 10    5 : 7    6 : 5 
*/

/*
2 5 -1
3 3 -1
2 -4 -1
*/

/*
2 6 5 7 -1
3 5 4 -4 5 8 -1
2 -2 -1
3 7 1 2 -1
3 -3 4 9 -1
*/
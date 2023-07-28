#include<stdio.h>
#include<stdlib.h>
const int m=5;
int c=0;
// m=4 is sufficient to cover all the vertices in such a way 


typedef struct gnode{
    int vertex;
    struct gnode* next;
}gnode;

void insertedge(gnode* graph[],int i,int adj){
    gnode* temp=(gnode*)malloc(sizeof(gnode));
    temp->vertex=adj;
    temp->next=NULL;
    if(graph[i]==NULL){
        graph[i]=temp;
    }
    else{
        temp->next=graph[i];
        graph[i]=temp;
    }
}

void readgraph(gnode* graph[],int n){
    for(int i=1;i<n;i++){
        graph[i]=NULL;
    }
    printf("Enter -1 to stop entering adjacents of asked vertex\n");
    for(int i=1;i<n;i++){
        printf("Enter adjacents of vertex %d: ",i);
        int adj;
        do{
            scanf("%d",&adj);
            if(adj==-1)
                break;
            insertedge(graph,i,adj);

        }while(1);
    }
}

void vertex_adjacents(gnode* graph[],int n){
    for(int i=1;i<n;i++){
        printf("Vertex : %d -> ",i);
        gnode* temp=graph[i];
        while(temp!=NULL){
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

void display(int color[],int n,int *flag){
    if(*flag==0)
        return;
    printf("-> ");
    for(int i=1;i<n;i++){
        printf("(%d:%d)",i,color[i]);
    }
    printf("\n---------------------------------------\n");
    // *flag=0;
    c++;
}

int possible(gnode* graph[],int kth_queen,int kth_color,int color[]){
    for(int i=1;i<kth_queen;i++){
        gnode* temp=graph[i];
        while(temp){
            if(temp->vertex==kth_queen&&kth_color==color[i]){
                return 0;
            }
            temp=temp->next;
        }
    }
    return 1;
}

void m_color(gnode* graph[],int n,int k,int color[],int *flag){
    for(int i=1;i<=m;i++){
        if(possible(graph,k,i,color)){
            color[k]=i;
            if(k<n-1){
                m_color(graph,n,k+1,color,flag);
            }
            else{
                display(color,n,flag);
            }
        }
    }
}

int main(){

    int n;printf("Total Kitne Vertex hai: ");
    scanf("%d",&n);n++;

    gnode * graph[n];
    readgraph(graph,n);
    
    // printing the graph given by user
    vertex_adjacents(graph,n);
    int color[n],flag=1;
    m_color(graph,n,1,color,&flag);
    // printing answer
    printf("\nTotal possible no of ways : %d\n", c);

    return 0;
}
/* 
n=7
2 3 -1
1 3 4 5 -1
1 2 4 7 -1
2 3 5 7 -1
2 4 6 7 -1
5 7 -1
3 4 5 6 -1
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

typedef struct pq_node{
    int vertex;
    int dist;
}pq_node;

typedef struct edge_node{
    int vertex;
    int wt;
    struct edge_node* next;
}edge_node;

typedef struct graph_node
{
    int pred;
    int ind_in_pq;
    bool in_pq;
    struct edge_node* adj_list;
}graph_node;

void insert_edge(graph_node graph[],int i,int adj,int weight){
    edge_node* temp=(edge_node*)malloc(sizeof(edge_node));
    temp->vertex=adj;
    temp->wt=weight;
    temp->next=NULL;
    if(graph[i].adj_list==NULL){
        graph[i].adj_list=temp;
    }
    else{
        temp->next=graph[i].adj_list;
        graph[i].adj_list=temp;
    }
}

void read_graph(graph_node graph[],int n){
    for(int i=1;i<=n;i++){
        graph[i].adj_list=NULL;
    }
    printf("Enter -1 to stop entering adjacents of asked vertex\n");
    for(int i=1;i<=n;i++){
        printf("Enter adjacents of vertex %d and wt of this edge: ",i);
        int adj,wt;
        do{
            scanf("%d",&adj);
            if(adj==-1)
                break;
            scanf("%d",&wt);
            insert_edge(graph,i,adj,wt);

        }while(1);
    }
}

void vertex_adjacents(graph_node graph[],int n){
    for(int i=1;i<n;i++){
        printf("Vertex : %d -> ",i);
        edge_node* temp=graph[i].adj_list;
        while(temp!=NULL){
            printf("%d(%d) ",temp->vertex,temp->wt);
            temp=temp->next;
        }
        printf("\n");
    }
}

void swap(graph_node graph[],pq_node *a,pq_node *b){
    int temp1=graph[a->vertex].ind_in_pq;
    graph[a->vertex].ind_in_pq=graph[b->vertex].ind_in_pq;
    graph[b->vertex].ind_in_pq=temp1;
    pq_node temp=*a;
    *a=*b;*b=temp;
}

void min_heapify(graph_node graph[],pq_node pq[],int i,int n){
    int min=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&&pq[min].dist>pq[left].dist)
        min=left;
    if(right<=n&&pq[min].dist>pq[right].dist)
        min=right;
    if(min!=i){
        swap(graph,&pq[min],&pq[i]);
        min_heapify(graph,pq,min,n);
    }
}

void buildminheap(graph_node graph[],pq_node pq[],int n){
    for(int i=n/2;i>0;i--){
        min_heapify(graph,pq,i,n);
    }
}

pq_node extract_min(graph_node graph[],pq_node pq[],int* n){
    pq_node ans=pq[1];
    pq[1]=pq[*n];
    graph[pq[1].vertex].ind_in_pq=1; // critical mistake
    (*n)--;
    min_heapify(graph,pq,1,*n);
    return ans;
}

void relax_dist(graph_node graph[],pq_node pq[],int i,int n,int new_wt){
	pq[i].dist=new_wt;
    while(i>1 && pq[i/2].dist>new_wt){
        swap(graph,&pq[i],&pq[i/2]);
		i/=2;
	}
}

void PRIM_MST(graph_node graph[],pq_node pq[],int n,int source){
    // graph_node ans_set[n];
    printf("ok\n");
    int N=n;
    for(int i=1;i<=n;i++){
        graph[i].pred=-1;
        graph[i].ind_in_pq=i;
        graph[i].in_pq=true;
        pq[i].dist=INT_MAX;
        pq[i].vertex=i;
    }
    pq[source].dist=0;
    int ans_set[n+1];
    for(int i=0;i<=n;i++){
        ans_set[i]=INT_MAX;
    }
    buildminheap(graph,pq,n);
    while(n>0){
        pq_node ans=extract_min(graph,pq,&n);
        int u=ans.vertex;
        graph[u].in_pq=false;
        ans_set[u]=ans.dist;
        edge_node* temp=graph[u].adj_list;
        while(temp){
            int v=temp->vertex;
            int wt=temp->wt;
            int index=graph[v].ind_in_pq;
            if(graph[v].in_pq==true && ans_set[v]>wt+ans_set[u]){
                relax_dist(graph,pq,index,n,ans_set[u]+wt);
                graph[v].pred=u;
                ans_set[v]=ans_set[u]+wt;
            }
            temp=temp->next;
        }
    }

    for(int i=1;i<=N;i++){
        printf("%d -> %d : %d\n",source,i,ans_set[i]);
    }

}

int main(){
    int n;
    printf("Total No of vertices?: ");
    scanf("%d",&n);

    graph_node graph[n+1];
    pq_node pq[n+1];
    read_graph(graph,n);

    vertex_adjacents(graph,n);

    PRIM_MST(graph,pq,n,1);
}

/*
2 3 4 6 5 9 -1
3 2 4 4 1 3 5 9 6 9 -1
2 2 4 2 6 8 7 9 -1
1 6 2 4 3 2 7 9 -1
1 9 2 9 6 8 10 18 -1
2 9 3 8 5 8 7 7 9 9 10 10 -1
3 9 4 9 6 7 9 5 8 4 -1
7 4 9 1 10 4 -1
6 9 7 5 8 1 10 3 -1
5 18 6 10 9 3 8 4 -1
N=10
ans : 38
*/ //correct hai ye

/*
2 28 6 10 -1
1 28 3 16 7 14 -1
2 16 4 12 -1
3 12 7 18 5 22 -1
4 22 7 24 6 25 -1
1 10 5 25 -1
2 14 4 18 5 24 -1
N=7
ans : 99
*/ // ye bhi correct hai

// use of shift + alt + a for multi line comment

/*
N=10
2 2 7 1 8 11 -1
1 2 7 3 3 3 -1
2 3 4 5 -1
3 5 5 7 -1
6 2 10 4 4 7 -1
7 9 10 8 8 4 5 2 -1
2 3 6 9 1 1 -1
1 11 9 6 6 4 -1
8 6 10 5 -1
6 8 5 4 9 5 -1 
ans : 33
*/ // ye bhi sahi hai bro
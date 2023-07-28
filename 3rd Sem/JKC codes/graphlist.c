#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// stack creation
typedef struct stackk{
    int size;
    int *array;
    int top;
}stackk;

stackk* stack_create(int size){
    stackk* stack=(stackk*)malloc(sizeof(stackk));
    stack->top=-1;
    stack->size=size;
    stack->array=(int*)malloc((size)*sizeof(int));
    return stack;
}

int isfulls(stackk* stack){
    return (stack->size==stack->top+1?1:0);
}

int isemptys(stackk* stack){
    return (stack->top==-1?1:0);
}

void pushs(stackk* stack,int data){
    if(isfulls(stack)){
        printf("Stack is full.\n");return;
    }
    stack->array[++stack->top]=data;
}

int pops(stackk* stack){
    if(isemptys(stack)){
        printf("Stack is already empty.\n");return ' '; 
    }
    return stack->array[stack->top--];
}

// queue creation
typedef struct queuee{
    int size;
    int top;
    int *arr;
}queuee;

queuee* queue_create(int size){
    queuee* q=(queuee*)calloc(1,sizeof(queuee));
    q->arr=(int*)calloc(size,sizeof(int));
    // q->size=0;
    // q->top=0;
    return q;
}

void popq(queuee* q){
    (q->top)++;
    (q->top)=(q->top)%100;
    (q->size)--;
}

void pushq(queuee* q,int a){
    (q->size)++;
    (q->arr)[((q->top)+(q->size)-1)%100]=a;
}

int isemptyq(queuee* q){
    return ((q->size)==0?1:0);
}

int frontq(queuee* q){
    if(isemptyq(q))
        return INT_MIN;
    return (q->arr)[(q->top)];
}

// typedef struct adjacents{
//     int adj;
//     struct adjacents* next;
// }adjacents;

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
    // printf("Print Adjacency matrix\n");
    // for(int i=1;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         int a;scanf("%d",&a);
    //         if(a==1){
    //             insertedge(graph,i,j);
    //         }
    //     }
    // }
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

int count_edges(gnode* graph[],int n){
    int count=0;
    for(int i=1;i<n;i++){
        gnode* temp=graph[i];
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
    }
    return count;
}

int * highest_outgoing_degree(gnode* graph[],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=0,total=0;
    for(int i=1;i<n;i++){
        int count=0;
        gnode* temp=graph[i];
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        max=(count>max?count:max);
    }
    for(int i=1;i<n;i++){
        int count=0;
        gnode* temp=graph[i];
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==max){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
}

int * lowest_outgoing_degree(gnode* graph[],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int min=INT_MAX,total=0;
    for(int i=1;i<n;i++){
        int count=0;
        gnode* temp=graph[i];
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        min=(count<min?count:min);
    }
    for(int i=1;i<n;i++){
        int count=0;
        gnode* temp=graph[i];
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==min){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
}

int * minimum_incoming_edges(gnode* graph[],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int min=INT_MAX,total=0;
    int vertices[n];
    for(int i=0;i<n;i++){
        vertices[i]=0;
    }
    for(int i=1;i<n;i++){
        gnode* temp=graph[i];
        while(temp!=NULL){
            vertices[temp->vertex]++;
            temp=temp->next;
        }
    }
    for(int i=1;i<n;i++){
        min=(min>vertices[i]?vertices[i]:min);
    }
    for(int i=1;i<n;i++){
        if(vertices[i]==min){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
}

int* maximum_incoming_edges(gnode* graph[],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=INT_MIN,total=0;
    int vertices[n];
    for(int i=0;i<n;i++){
        vertices[i]=0;
    }
    for(int i=1;i<n;i++){
        gnode* temp=graph[i];
        while(temp!=NULL){
            vertices[temp->vertex]++;
            temp=temp->next;
        }
    }
    for(int i=1;i<n;i++){
        max=(max<vertices[i]?vertices[i]:max);
    }
    for(int i=1;i<n;i++){
        if(vertices[i]==max){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
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

int * node_connected_to_all(gnode* graph[],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=0,total=0;
    
    for(int i=1;i<n;i++){
        int count=0;
        gnode* temp=graph[i];
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==n-2){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
}

int * unconnected_node(gnode* graph[],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=0,total=0;
    int out[n];
    int in[n];
    for(int i=1;i<n;i++){
        in[i]=0;out[i]=0;
    }
    for(int i=1;i<n;i++){
        int count=0;
        gnode* temp=graph[i];
        while(temp!=NULL){
            in[temp->vertex]++;
            count++;
            temp=temp->next;
        }
        out[i]=count;
    }
    for(int i=1;i<n;i++){
        if(in[i]==0&&out[i]==0){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
}

void DFS_visit(gnode* graph[],int parent[],int trav_status[],int i){
    trav_status[i]=1;
    printf("%d ",i);
    gnode* temp=graph[i];
    while(temp!=NULL){
        if(trav_status[temp->vertex]==0){
            parent[temp->vertex]=i;
            DFS_visit(graph,parent,trav_status,temp->vertex);
        }
        temp=temp->next;
    }
}

void DFS(gnode* graph[],int n){
    int trav_status[n];
    int parent[n];
    for(int i=1;i<n;i++){
        trav_status[i]=0;
        parent[i]=-1;
    }
    for(int i=1;i<n;i++){
        if(trav_status[i]==0){
            DFS_visit(graph,parent,trav_status,i);
        }
    }
}

void BFS_visit(gnode* graph[],int parent[],int trav_status[],int i,queuee* q){
    // printf("**%d\n",empty(q));
    pushq(q,i);
    // printf("%d\n",front(q));
    trav_status[i]=1;
    parent[i]=-1;;
    while(!isemptyq(q)){
        int a=frontq(q);
        printf("%d ",a);
        popq(q);
        gnode* temp=graph[a];
        while(temp!=NULL){
            if(trav_status[temp->vertex]==0){
                parent[temp->vertex]=a;
                pushq(q,temp->vertex);
                trav_status[temp->vertex]=1;
            }
            temp=temp->next;
        }
    }
}

// void BFS_visit(gnode* graph[],int parent[],int trav_status[]){
//     while(!q.empty()){
//         int a=q.front();
//         printf("%d ",a);
//         q.pop();
//         gnode* temp=graph[a];
//         while(temp!=NULL){
//             if(trav_status[temp->vertex]==0){
//                 parent[temp->vertex]=a;
//                 q.push(temp->vertex);
//                 trav_status[temp->vertex]=1;
//             }
//             temp=temp->next;
//         }
//     }
// }

void BFS(gnode* graph[],int n){
    int trav_status[n];
    int parent[n];
    struct queuee *q=queue_create(50);
    for(int i=1;i<n;i++){
        trav_status[i]=0;
        parent[i]=-1;
    }
    for(int i=1;i<n;i++){
        if(trav_status[i]==0){
            BFS_visit(graph,parent,trav_status,i,q);
        }
    }
}

void junior(gnode* graph[],int i){
    gnode* temp=graph[i];
    while(temp){
        gnode* temp2=graph[temp->vertex];
        while(temp2){
            printf("%d ",temp2->vertex);
            temp2=temp2->next;
        }
        temp=temp->next;
    }
}

void DFS_visit_topo(gnode* graph[],int parent[],int trav_status[],int i,stackk* stack){
    trav_status[i]=1;
    // printf("%d ",i);
    gnode* temp=graph[i];
    while(temp!=NULL){
        if(trav_status[temp->vertex]==0){
            parent[temp->vertex]=i;
            DFS_visit_topo(graph,parent,trav_status,temp->vertex,stack);
        }
        temp=temp->next;
    }
    pushs(stack,i);
}

int* topologicalsort(gnode* graph[],int n){
    stackk* stack=stack_create(n);
    int* topo=(int*)malloc(n*sizeof(int));
    int size=0;
    int trav_status[n];
    int parent[n];
    for(int i=1;i<n;i++){
        trav_status[i]=0;
        parent[i]=-1;
    }
    for(int i=1;i<n;i++){
        if(trav_status[i]==0){
            // trav_status[i]=1;
            DFS_visit_topo(graph,parent,trav_status,i,stack);
        }
    }
    while(!isemptys(stack)){
        topo[++size]=pops(stack);
    }
    return topo;
}

gnode** transpose(gnode* graph[],int n){
    gnode** trans=(gnode**)malloc(n*sizeof(gnode*));
    for(int i=1;i<n;i++){
        trans[i]=NULL;
    }
    for(int i=1;i<n;i++){
        gnode* temp=graph[i];
        while(temp){
            int j=temp->vertex;
            if(trans[j]==NULL){
                trans[j]=(gnode*)malloc(sizeof(gnode));
                trans[j]->vertex=i;
                trans[j]->next=NULL;
            }
            else{
                gnode* temp1=(gnode*)malloc(sizeof(gnode));
                temp1->next=trans[j];
                temp1->vertex=i;
                trans[j]=temp1;
            }
            temp=temp->next;
        }
    }
    return trans;
}

void dfs_scc(gnode* tra_graph[],int visit[],int i){
    printf("%d ",i);visit[i]=1;
    gnode* temp=tra_graph[i];
    while(temp){
        if(visit[temp->vertex]==0){
            dfs_scc(tra_graph,visit,temp->vertex);
        }
        temp=temp->next;
    }
}

void SCC(gnode* graph[],int n,int* topo){
    gnode** trans=transpose(graph,n);
    printf("Transpose is given below: \n");
    vertex_adjacents(trans,n);
    int visited[n],scc=0;
    for(int i=1;i<n;i++){visited[i]=0;}
    for(int i=1;i<n;i++){
        if(visited[topo[i]]==0){
            printf("\nSCC no. %d :",++scc);
            dfs_scc(trans,visited,topo[i]);
        }
    }
}

int main(){

    int n;printf("Total Kitne Vertex hai: ");
    scanf("%d",&n);n++;

    gnode * graph[n];
    readgraph(graph,n);

    vertex_adjacents(graph,n);
    printf("No of Edges are: %d\n",count_edges(graph,n));


    int *out=highest_outgoing_degree(graph,n);
    // first value of the incoming array pointer contains total no of nodes having highest outgoing degree
    printf("\nVertex having highest outgoing degree is/are: ");
    for(int i=0;i<out[0];i++){
        printf("%d ",out[i+1]);
    }


    int *outlow=lowest_outgoing_degree(graph,n);
    // first value of the incoming array pointer contains total no of nodes having highest outgoing degree
    printf("\nVertex having lowest outgoing degree is/are: ");
    for(int i=0;i<outlow[0];i++){
        printf("%d ",outlow[i+1]);
    }
    

    int *all=node_connected_to_all(graph,n);
    // first value of the incoming array pointer contains total no of nodes connected to all the other vertices
    if(all[0]==0){
        printf("\nNo Such vertex exist having connection to all the other vertices\n");
    }
    else{
        printf("\nVertex Connected to all the other Vertices is/are: ");
        for(int i=0;i<all[0];i++){
            printf("%d ",all[i+1]);
        }
    }


    int *min=minimum_incoming_edges(graph,n);
    // first value of the incoming array pointer contains total no of nodes having mimimum incoming edges
    printf("\nVertex having mimimum Number of Incoming Edges is/are: ");
    for(int i=0;i<min[0];i++){
        printf("%d ",min[i+1]);
    }


    int *max=maximum_incoming_edges(graph,n);
    // first value of the incoming array pointer contains total no of nodes having mimimum incoming edges
    printf("\nVertex having maximum Number of Incoming Edges is/are: ");
    for(int i=0;i<max[0];i++){
        printf("%d ",max[i+1]);
    }

    int *t=unconnected_node(graph,n);
    // first value of the incoming array pointer contains total no of nodes which are not connected to any vertex
    if(t[0]==0){
        printf("\nAll vertex are connected to at least one vertex");
    }
    else{
        printf("\nVertex that are not connected is/are: ");
        for(int i=0;i<t[0];i++){
            printf("%d ",t[i+1]);
        }
    }


    printf("\n\nDepth first search\n");
    DFS(graph,n);
    printf("\n\nBreadth first search\n");
    BFS(graph,n);

    printf("\n\nJunior of specified vertices.\n");
    junior(graph,2);

    printf("\n\nTopological sort is as follows\n-> ");
    int* topo=topologicalsort(graph,n);
    for(int i=1;i<n;i++){
        printf("%d ",topo[i]);
    }

    printf("\n\nprinting SCC component: \n");
    SCC(graph,n,topo);

} 
/* 
example of directed graph

n = 7
2 3 4 -1
4 6 -1
4 5 -1
5 6 -1
6 7 -1
7 -1
-1

n=8
2 -1
5 6 3 -1
4 7 -1
3 8 -1
1 6 -1
7 -1
6 8 -1
-1
*/

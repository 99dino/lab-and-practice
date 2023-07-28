#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// #define N 20
const int N=20;

//
//
//this code serve the purpose for the vertices starting from 0//
//
//

int count_edges(int graph[N][N],int n){
    int count=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            count+=(graph[i][j]==1?1:0);
        }
    }
    return count;
}

int * highest_outgoing_degree(int graph[N][N],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=0,total=0;
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=1;j<n;j++){
            if(graph[i][j]==1)
                count++;
        }
        max=(count>max?count:max);
    }

    for(int i=1;i<n;i++){
        int count=0;
        for(int j=1;j<n;j++){
            if(graph[i][j]==1)
                count++;
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

int * minimum_incoming_edges(int graph[N][N],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int min=INT_MAX,total=0;
    for(int j=1;j<n;j++){
        int count=0;
        for(int i=1;i<n;i++){
            if(graph[i][j]==1)
                count++;
        }
        min=(count<min?count:min);
    }
    for(int j=1;j<n;j++){
        int count=0;
        for(int i=1;i<n;i++){
            if(graph[i][j]==1)
                count++;
        }
        if(count==min){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=j;
        }
    }
    return array;
}

int * node_connected_to_all(int graph[N][N],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=0,total=0;
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=1;j<n;j++){
            if(graph[i][j]==1)
                count++;
        }
        if(count==n-1){
            array[0]++;
            total++;
            array=(int*)realloc(array,(total+1)*sizeof(int));
            array[total]=i;
        }
    }
    return array;
}

int * unconnected_node(int graph[N][N],int n){
    int *array=(int*)malloc(sizeof(int));
    *array=0;
    int max=0,total=0;
    int out[n];
    int in[n];
    for(int i=1;i<n;i++){
        in[i]=0;out[i]=0;
    }
    for(int j=0;j<n;j++){
        int count=0;
        for(int i=0;i<n;i++){
            if(graph[i][j]==1){
                out[i]++;
                count++;
            }
        }
        in[j]=count;
        if(count==0){
            
        }
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

int main(){
    printf("enter vertex number and its adjacents\n");
    int n;printf("Total Kitne Vertex hai: ");
    scanf("%d",&n);n++;
    //initialisation
    int graph[N][N];
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            graph[i][j]=0;
        }
    }
    // one way to take inputs
    // printf("Enter adjacency matrix\n");
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         scanf("%d",&graph[i][j]);
    //     }
    // }
   
    printf("Enter adjacents for the asked vertex\n");
    printf("press -1 to stop telling adjacents of a vertex\n");
    for(int i=1;i<n;i++){
        printf("Adajcents of Vertex %d: ",i);
        int j;
        do{
            scanf("%d",&j);
            if(j==-1)
                break;
            graph[i][j]=1;
        }while(1);
    }
    
    // another way of taking inputs
    // printf("press -1 to stop telling adjacents of a vertex\n");
    // for(int i=0;i<n;i++){
    //     printf("Enter Vertex: ");
    //     int j,k;
    //     scanf("%d",&k);
    //     printf("Enter its adjacents: ");
    //     do{
    //         scanf("%d",&j);
    //         if(j==-1)
    //             break;
    //         graph[k][j]=1;
    //     }while(1);
    // }

    printf("\n");
    // printing adjacency matrix
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal no of edges is %d\n",count_edges(graph,n));
    
    int *out=highest_outgoing_degree(graph,n);
    // first value of the incoming array pointer contains total no of nodes having highest outgoing degree
    printf("Vertex having highest outgoing degree is/are: ");
    for(int i=0;i<out[0];i++){
        printf("%d ",out[i+1]);
    }

    int *all=node_connected_to_all(graph,n);
    // first value of the incoming array pointer contains total no of nodes connected to all the other vertices
    if(all[0]==0){
        printf("\nNo Such vertex exist having connextion to all the other vertices\n");
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

    int *not=unconnected_node(graph,n);
    // first value of the incoming array pointer contains total no of nodes which are not connected to any vertex
    if(not[0]==0){
        printf("\nAll vertex are connected to at least one vertex");
    }
    else{
        printf("\nVertex that are not connected is/are: ");
        for(int i=0;i<not[0];i++){
            printf("%d ",not[i+1]);
        }
    }
}

// some sample test cases
// n=6
// 1 -1
// 2 0 4 3 5 -1
// 1 4 3 -1
// 5 1 2 4 -1
// 2 1 3 -1
// 3 1 -1
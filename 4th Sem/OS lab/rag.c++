// #include<bits/stdc++.h>
// using namespace std;

// int n,m;
// vector<int> res,pro;
// vector<pair<int,int>> topo;
// vector<vector<int>> graph;

// void dfs(int src,int type){
//     if(type==1){
//         res[src]++;
//         for(int j=1;j<=n;j++){
//             if(graph[j][src]==-1&&!pro[j]){
//                 dfs(j,0);
//             }
//         }
//     }
//     else{
//         pro[src]++;
//         for(int j=1;j<=m;j++){
//             if(graph[src][j]==1&&!res[j]){
//                 dfs(j,1);
//             }
//         }
//     }
//     topo.push_back({src,type});
// }


// int main(){
//     cin>>n>>m;
//     graph=vector<vector<int>> (n+1);
//     res=vector<int> (n+1,0);
//     pro=vector<int> (n+1,0);
//     // topo=vector<pair<int,int>> (n);
//     for(int i=1;i<=n;i++){
//         graph[i]=vector<int> (m+1);
//         for(int j=1;j<=m;j++){
//             cin>>graph[i][j];
//         }
//     }

//     for(int i=1;i<=n;i++){
//         if(!pro[i])
//             dfs(i,0);
//     }

//     //1 is for resource and 0 is for process
//     reverse(topo.begin(),topo.end());

//     for(int i=0;i<n+1;i++){res[i]=pro[i]=0;}

//     if(topo[0].second==1){
//         res[topo[0].first]++;
//     }
//     else{
//         pro[topo[0].first]++;
//     }

//     for(int i=1;i<topo.size();i++){
//         if(topo[i].second==1){
//             res[topo[i].first]++;
//             for(int j=1;j<=n;j++){
//                 if(graph[j][topo[i].first]==-1&&pro[j]){
//                     cout<<"cycle found\n";return 0;
//                 }
//             }
//         }
//         else{
//             pro[topo[i].first]++;
//             for(int j=1;j<=m;j++){
//                 if(graph[topo[i].first][j]==1&&res[j]){
//                     cout<<"cycle found\n";return 0;
//                 }
//             }

//         }
//         // cout<<topo[i].first<<" "<<topo[i].second<<endl;

//     }
//     cout<<"cycle not found\n";

// }

// /* 




// 5 5
// 1 -1 0 0 0
// -1 0 1 1 1
// 0 0 0 -1 1
// 0 1 0 0 -1
// 0 0 -1 0 0



// cycle hai
//  */



// /* 

// 4 2
// 1 -1
// -1 0
// -1 1
// 0 -1

// cycle hai
//  */

// /* 
// 3 3
// 1 -1 0
// -1 -1 1
// 0 0 1

// no cycle
//  */




#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<pair<int,int>> topo;
vector<vector<int>> graph,visit;

void dfs(int src,int type){
    visit[type][src]++;

    if(type==1){
        // res[src]++;
        for(int j=1;j<=n;j++){
            if(graph[j][src]==-1&& !visit[0][j]){
                //  !pro[j]
                dfs(j,0);
            }
        }
    }
    else{
        // pro[src]++;
        for(int j=1;j<=m;j++){
            if(graph[src][j]==1&&!visit[1][j]){
                // !res[j]
                dfs(j,1);
            }
        }
    }
    topo.push_back({src,type});
}


int main(){
    cin>>n>>m;
    graph=vector<vector<int>> (n+1);
    visit=vector<vector<int>> (2,vector<int> (n+1));
    for(int i=1;i<=n;i++){
        graph[i]=vector<int> (m+1);
        for(int j=1;j<=m;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        if(!visit[0][i])
            dfs(i,0);
    }

    //1 is for resource and 0 is for process
    reverse(topo.begin(),topo.end());

    for(int i=0;i<n+1;i++){visit[0][i]=visit[1][i]=0;}
    
    visit[topo[0].second][topo[0].first]++;

    for(int i=1;i<topo.size();i++){
        visit[topo[i].second][topo[i].first]++;
        if(topo[i].second==1){
            // res[topo[i].first]++;
            for(int j=1;j<=n;j++){
                if(graph[j][topo[i].first]==-1&& visit[0][j]){
                    //  pro[j]
                    cout<<"cycle found\n";return 0;
                }
            }
        }
        else{
            // pro[topo[i].first]++;
            for(int j=1;j<=m;j++){
                if(graph[topo[i].first][j]==1&&visit[1][i]){
                    // res[j]
                    cout<<"cycle found\n";return 0;
                }
            }

        }
        // cout<<topo[i].first<<" "<<topo[i].second<<endl;
    }
    cout<<"cycle not found\n";

}

/* 

5 5
1 -1 0 0 0
-1 0 1 1 1
0 0 0 -1 1
0 1 0 0 -1
0 0 -1 0 0

cycle hai
 */
/* 

4 2
1 -1
-1 0
-1 1
0 -1

cycle hai
 */

/* 
3 3
1 -1 0
-1 -1 1
0 0 1

no cycle
 */
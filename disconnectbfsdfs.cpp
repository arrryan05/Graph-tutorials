#include<bits/stdc++.h>
using namespace std;

void printdfs(int** adj,int n,int start,bool* visited){
    cout<<start<<endl;
    visited[start] = true;
    for(int i=0;i<n;i++){
        if(i==start) continue;
        if(adj[start][i]==1){
            if(visited[i])  continue;
            printdfs(adj,n,i,visited);
        }
    }
}

void printbfs(int** adj,int n,int start,bool* visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<endl;
        for(int i=0;i<n;i++){
            if(i==curr) continue;
            if(visited[i]) continue;
            if(adj[curr][i]==1){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs(int** adj,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printbfs(adj,n,i,visited);
        }
    }
}

void dfs(int** adj, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printdfs(adj,n,i,visited);
        }
    }
}

int main (){
    int n,e;
    cin>>n>>e;
    int** adj = new int*[n];
    for(int i=0;i<n;i++){
        adj[i] = new int[n];
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int s,e;
        cin>>s>>e;
        adj[s][e]=1;
        adj[e][s]=1;
    }

    bfs(adj,n);
    dfs(adj,n);
    return 0;

}
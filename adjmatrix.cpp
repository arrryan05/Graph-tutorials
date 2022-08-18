#include<bits/stdc++.h>
using namespace std;

void print(int** adj,int n,int start,bool* visited){
    cout<<start<<endl;
    visited[start] = true;
    for(int i=0;i<n;i++){
        if(i==start) continue;
        if(adj[start][i]==1){
            if(visited[i])  continue;
            print(adj,n,i,visited);
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

    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    print(adj,n,0,visited);
    return 0;

}
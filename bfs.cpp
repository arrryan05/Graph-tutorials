#include<bits/stdc++.h>
using namespace std;

void print(int** adj,int n,int start,bool* visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        cout<<q.front()<<endl;
        int curr = q.front();
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
    for(int i=0;i<n;i++){
        if(!visited[i]){
            print(adj,n,0,visited);
        }
    }
    return 0;

}
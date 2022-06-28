/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/
#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>&adj, int i, vector<int>&visited, vector<int>&recSt){
    visited[i] = 1;
    recSt[i] = 1;
    for(auto k : adj[i]){
        if(visited[k]==0 && dfs(adj, k, visited, recSt)) return true;
        else if (recSt[k]==1) return true;
    }
    recSt[i]=0;
    return false;
}

bool detectLoop(vector<vector<int>>&adj){
    int n = adj.size();
     vector<int> visited(n,0);
    vector<int> recSt(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i])
            if(dfs(adj,i,visited,recSt)) return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    // adjacency matrix
    vector<vector<int>> adjMat(n,vector<int>(n,0));
    vector<bool> visited(n,false);
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) cin>>adjMat[i][j];
    }
    // adjacency matrix from the input matrix
    vector<vector<int>> adjList(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adjMat[i][j]!=0)
            adjList[i].push_back(j);
        }
    }
    if(detectLoop(adjList)) cout<<"Cycle exists";
    else cout<<"No cycle exists";

}

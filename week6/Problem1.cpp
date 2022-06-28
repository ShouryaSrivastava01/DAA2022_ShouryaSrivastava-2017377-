/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/

#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>&adjList, vector<bool>&visited,int i, int target){

    if(visited[i]) return false;            // if node is visited
    if(i==target) return true;
    // mark the node visited
    visited[i]=true;
    for(auto it : adjList[i]){
        if(dfs(adjList,visited,it,target)) return true;
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
    int start, end;
    cin>>start>>end;
    if(dfs(adjList,visited,start-1,end-1)) cout<<"Yes Path Exists";
    else cout<<"No Such Path Exists";

}

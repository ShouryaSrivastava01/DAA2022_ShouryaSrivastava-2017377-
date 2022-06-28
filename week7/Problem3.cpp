/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/
#include<bits/stdc++.h>
using namespace std;

int minPath;
void dfs(vector<vector<pair<int,int>>>&edges, int start, int target, int weight, int k){
    if(k==0 && start==target){
       minPath = min(minPath, weight);
    }
    if(k==0) return;

    for(auto v : edges[start]){
        dfs(edges, v.second, target, weight+v.first, k-1);
    }
}

int main(){
    int n;
    cin>>n;
    // adjacency matrix
    vector<vector<int>> adjMat(n,vector<int>(n,0));
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) cin>>adjMat[i][j];
    }
   
    // pair(weight, source)
    vector<vector<pair<int,int>>> edges(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            if(adjMat[i][j]>0) {
                edges[i].push_back({adjMat[i][j], j});
            }
        }
    }
    int start, end,k;
    cin>> start>> end;
    cin>>k;
    minPath = INT_MAX;
    dfs(edges, start-1, end-1,0,k );

    if(minPath==INT_MAX) cout<<"No path of length k is available";
    else cout<<"Weight of shortest path from ("<<start<<","<<end<<") with "<<k<<" edges : "<<minPath;
   



}
/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/
#include<bits/stdc++.h>
using namespace std;

// print the parh from the destination to source
void printPath(vector<int>&parent, int i){
    cout<<i+1<<" ";
    if(parent[i]==-1) return;
    printPath(parent,parent[i]);
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
   
    // pair(weight, source)
    vector<vector<pair<int,int>>> edges(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            if(adjMat[i][j]>0) {
                edges[i].push_back({adjMat[i][j], j});
            }
        }
    }
    int start;
    cin>> start;
   
    vector<int> dist(n,INT_MAX);
    vector<int> parent(n,-1);
    
    dist[start-1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start-1});
    while(!pq.empty()){
        auto it =pq.top();
        pq.pop();
        int src = it.second;
        for(auto n : edges[src]){
            int node = n.second;
            int weight = n.first;

            if(dist[node]>dist[src]+weight) {
                parent[node]=src;
                dist[node]=dist[src]+weight;
                pq.push({dist[node],node});
            }
        }
    }

   for(i=0;i<dist.size(); i++){
       printPath(parent,i);
       cout<<": "<<dist[i]<<endl;
   }




}
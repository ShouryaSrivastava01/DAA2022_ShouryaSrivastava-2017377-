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

bool bellmanFord(int n,vector<vector<int>>&edges, vector<int>&distance, vector<int>&parent,int start){
    distance[start-1]=0;
    int src, dest, weight;
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=0;j<edges.size();j++){
            src= edges[j][0];
            dest=edges[j][1];
            weight= edges[j][2];
            if(distance[src]!=INT_MAX && distance[dest]> distance[src]+weight){
                parent[dest]=src;
                distance[dest]=distance[src]+weight;
            }
        }

    }
    for(j=0;j<edges.size();j++){
            src= edges[j][0];
            dest=edges[j][1];
            weight= edges[j][2];
            if(distance[dest]> distance[src]+weight){
                return true;
            }
        }
    return false;
}

int main(){
    int n;
    cin>>n;
    // edges list
    //{source, destinatin,weight}
    vector<vector<int>> edges;
    int i, j, weight;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>> weight;
            if(weight!=0)
                edges.push_back({i,j,weight});
        }
    }
    
    int start;
    cin>> start;
   
    vector<int> dist(n,INT_MAX);
    vector<int> parent(n,-1);
   
if(bellmanFord(n,edges,dist,parent,start)) cout<<"Negative weight cycle exists";
else{
   for(i=0;i<dist.size(); i++){
       printPath(parent,i);
       cout<<": "<<dist[i]<<endl;
   }


}



}
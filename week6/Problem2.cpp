/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/
#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<vector<int>>&adjList){
    int n = adjList.size();
    vector<int> color(n,-1);  // using color for visited as well as coloring the nodes -1 not visited
    for(int i=0;i<n;i++){
        //not visited
        if(color[i]==-1){
            //simple bfs
            queue<int> q;
            q.push(0);
            color[i]=i;
            while(!q.empty()){
                int node = q.front();
                q.pop();
               for(auto it : adjList[node]){
                    if(color[it]==-1){
                        color[it] = color[node]+1;  // color the node 
                        q.push(it);
                    }
                    else if(color[it]==color[node]) // two nodes having same color are adjacent node hence bipartite in not possible
                        return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    // adjacency matrix
    vector<vector<int>> adjMat(n,vector<int>(n,0));
    vector<int> color(n,-1);
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
   if(checkBipartite(adjList)) cout<<"Yes Bipartite";
   else cout<<"Not Bipartite";

}

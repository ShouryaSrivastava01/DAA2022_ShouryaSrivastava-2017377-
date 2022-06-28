/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/
#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX


void floydWarshall(vector<vector<int>>graph){
    int V = graph.size();   
    int dist[V][V], i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cout<<"SHORTEST DISTANCE MATRIX"<<endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j]<<" ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adjMat(n,vector<int>(n));
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            string input;
            cin>>input;
            if(input == "INF")
             adjMat[i][j] = INT_MAX;
             else
                adjMat[i][j]= stoi(input);
             }

             }
    floydWarshall(adjMat);
}
/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/
#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = find(parent, parent[x]);
    return parent[x];
}

void uni(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int r_x = find(parent, x);
    int r_y = find(parent, y);

    if (r_x == r_y)
        return;

    if (rank[r_x] > rank[r_y])
        parent[r_y] = r_x;
    else if (rank[r_y] > rank[r_x])
        parent[r_x] = r_y;
    else
    {
        parent[r_y] = r_x;
        rank[x]++;
    }
}

int main()
{
    int n;
    cin >> n;
    // edges list
    //{source, destinatin,weight}
    // vector<vector<int, pair<int,int>>> edges;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> parent(n);
    vector<int> rank(n, 0);
    int i, j, weight;
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
        for (j = 0; j < n; j++)
        {
            cin >> weight;
            if (weight != 0)
                edges.push_back({weight, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    // for (auto e : edges)
    //     cout << e.first << " " << e.second.first << "-" << e.second.second << endl;
    int ans = 0;
    for (auto e : edges)
    {
        int weight = e.first;
        int src = e.second.first;
        int dest = e.second.second;
        if (find(parent, src) != find(parent, dest))
        {
            ans += weight;
            uni(parent, rank, src, dest);
        }
    }
    cout<<"Minimum Spanning Weight : " << ans << endl;
}
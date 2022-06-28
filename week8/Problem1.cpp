/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // edges list
    //{source, destinatin,weight}
    vector<vector<pair<int, int>>> edges(n);
    int i, j, weight;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> weight;
            if (weight != 0)
                edges[i].push_back({weight, j});
        }
    }

    vector<bool> mset(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int src = it.second;
        if (mset[src] == false)
            ans += it.first;
        else
            continue;
        mset[src] = true;

        for (auto v : edges[src])
        {

            if (!mset[v.second])
            {
                pq.push({v.first, v.second});
            }
        }
    }
    cout<<"Minimum Spanning Weight : " << ans;
}

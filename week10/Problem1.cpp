/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, f;
    cin >> n;
    vector<pair<int, int>> activity(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        activity[i].first = s;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f;
        activity[i].second = f;
    }
    vector<pair<int, int>> helper = activity;

    sort(helper.begin(), helper.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    vector<int> selected;
    int count = 0, currEnd = 0, index;

    for (int i = 0; i < n; i++)
    {
        if (helper[i].first >= currEnd)
        {
            index = find(activity.begin(), activity.end(), helper[i]) - activity.begin();
            selected.push_back(index + 1);
            count++;
            currEnd = helper[i].second;
        }
    }

    cout << "No. of non-conflicting activities: " << count << "\n";
    cout << "List of selected activities: ";
    for (auto it : selected)
        cout << it << " ";

    return 0;
}
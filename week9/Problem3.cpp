/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, cost = 0, prev_merge=0;
    cin>>n;
    vector<int> files(n);
    for(i=0;i<n;i++) cin>>files[i];

    //sort the files greedy
    sort(files.begin(), files.end());

    prev_merge = files[0];
    for(i=1;i<n;i++) {
        prev_merge += files[i];
        cost+=prev_merge;
    }

    cout<<cost<<endl;
}
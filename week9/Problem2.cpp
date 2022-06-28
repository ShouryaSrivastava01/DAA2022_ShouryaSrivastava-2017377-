/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, cap;
    double max = 0;
    cin>>n;
    // {value,weight} pair
    vector<pair<int,int>> p(n);
    for(i=0;i<n;i++) cin>>p[i].second;  // input the weights
    for(i=0;i<n;i++) cin>>p[i].first;   // input the values
    cin>>cap;
    // {ratio,item no} pair
    vector<pair<double,int>> ratio(n);
    for(i=0;i<n;i++)
        ratio[i] = {(p[i].first/(double)p[i].second),i};
        sort(ratio.begin(),ratio.end());
        cout<<"Item - weight"<<endl;
    for(i=n-1; i>=0; i--){
        if((cap - p[ratio[i].second].second)<0){
            max += cap*ratio[i].first;
            cout<<ratio[i].second+1<<" - "<<cap<<endl;
            break;
        }
        else{
            cout<<ratio[i].second+1<<" - "<<p[ratio[i].second].second<<endl;
            max += p[ratio[i].second].first;
            cap -= p[ratio[i].second].second;

        }

    }
    cout<<"Maximum value : "<<max;

}
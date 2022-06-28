/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Implement jump search

*/

/*
Algorithm
1. compute the size of array
2. 
*/

#include<iostream>
#include<vector>
#include<Math.h>
using namespace std;

void jumpSearch(vector<int>&arr, int key){
    int n = arr.size();
    int m = sqrt(n);
    int i = 0;
    // search in group of m pair
    while(arr[m]<=key && m<n){
        i=m;
        m+=m;
        if(m>n-1) m=n;
    }
    // linear search 
    for(int x=i; x<m; x++){
            if(arr[x]==key) {
                cout<<x;
                return ;
            }
    }
   cout<<"Key not found"<<endl;
   return;
}

int main(){
    int n;
    cout<<"Enter the size of array : "; 
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key to be searched : ";
    cin>>key;
    jumpSearch(arr, key);
}


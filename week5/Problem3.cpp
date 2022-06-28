/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
*/

#include <iostream>
#include<vector>
using namespace std;





int main()
{
    int m, n;
    cin>>m;
    vector<int> arr1(m);
    for(int i=0; i<m; i++) cin>>arr1[i];
    cin>>n;
    vector<int> arr2(n);
    for(int i=0; i<n; i++) cin>>arr2[i];
    int p1 = 0, p2 = 0;
    while(p1<m && p2<n){
       if(arr1[p1]>arr2[p2]) p2++;
       else if(arr1[p1]<arr2[p2]) p1++;
       else {
           cout<<arr1[p1]<<" ";
           p1++;
           p2++;
       }
    }
          
    
    return 0;
}
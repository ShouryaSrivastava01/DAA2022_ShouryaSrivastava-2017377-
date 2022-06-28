/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):

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
                cout<<"Preset"<<endl;
                return ;
            }
    }
   cout<<"Not Present"<<endl;
   return;
}

int main(){
    int n, size;
    cout<<"Enter the number of testcases : ";
    cin>>n;
    while(n--){
    cout<<"Enter the size of the array : ";
    cin>>size;
    vector<int> arr(size);
    for(int i=0; i<size ; i++)
        cin>>arr[i];

    int key;
    cout<<"Enter the key to be searched : ";
    cin>>key;
    jumpSearch(arr, key);
    } 
}


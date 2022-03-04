/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given an array of non-negative, design a linear algorithm and implement it using a program to find 
whether key element is present or not and also find total number of comparison.
*/
#include <iostream>
using namespace std;

int linearSearch(int *arr, int size, int key){
    // to count number of comparsion
    int cmp=1;
    for(int i=0;i<size; i++){
        if(key==arr[i])
            return cmp;
        
        //increment the cmp on each traversal
        cmp++;
    }
    //if key is not present in the given array
    return -1;
    
}

int main()
{
    int n, key;
    cout<<"Enter the size of the array : ";
    cin>> n;
    int arr[n];
    cout<<"Enter the elements : ";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to be searched : ";
    cin>>key;
    
    if(linearSearch(arr,n,key)==-1) cout<<"Given key not found ";
    else cout<<"Given key found and Number of comparison to find given key : "<<linearSearch(arr,n,key);


    return 0;
}
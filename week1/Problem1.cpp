/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
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
    int n;
    cin>>n;
    while(n--){
    int size, key;
    cout<<"Enter the size of the array : ";
    cin>> size;
    int arr[size];
    cout<<"Enter the elements : ";
    for(int i=0; i<size ; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to be searched : ";
    cin>>key;
    
    if(linearSearch(arr,size,key)==-1) cout<<"Not Present "<<size<<endl;
    else cout<<"Present "<<linearSearch(arr,size,key)<<endl;
    }


    return 0;
}
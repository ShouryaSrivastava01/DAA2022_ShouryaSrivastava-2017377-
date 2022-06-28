/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/

#include <iostream>
using namespace std;
int cmp = 0;
//given array is sorted, binary search is best suited for searching 
bool binarySearch(int *arr, int size, int key){
    int left=0, right=size-1, mid=0;
    while(left<=right){
        cmp+=1;
        mid=left+(right-left)/2;
        if(arr[mid]==key){
            return true;
        }
        // move left
        else if(arr[mid]>key){
            right=mid-1;
        }
        //move right
        else {
            left=mid+1;
        }
        // increment the comparison
    }
    return false;
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
    cout<<"Enter the elements in sorted order : ";
    for(int i=0; i<size ; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to be searched : ";
    cin>>key;
    
    if(!binarySearch(arr,size,key)) cout<<"Not Present ";
    else cout<<"Present ";
    cout<<cmp<<endl;
    cmp=0;
    }

    return 0;
}
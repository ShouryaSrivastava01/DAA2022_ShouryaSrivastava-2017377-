/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : Given a sorted array of positive number, desing an algorithm and implement it using a program to find whether
the given key element is present or not and also find total number of comparison.
*/

#include <iostream>
using namespace std;

//given array is sorted, binary search is best suited for searching 
int binarySearch(int *arr, int size, int key){
    int left=0, right=size-1, mid=0, cmp=1;
    while(left<=right){
        mid=left+(right-left)/2;
        if(arr[mid]==key){
            return cmp;
        }
        // move left
        else if(arr[mid]>key){
            right=mid;
        }
        //move right
        else {
            left=mid+1;
        }
        // increment the comparison
        cmp++;
    }
    return -1;
}

int main()
{
    int n, key;
    cout<<"Enter the size of the array : ";
    cin>> n;
    int arr[n];
    cout<<"Enter the elements in sorted order : ";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to be searched : ";
    cin>>key;
    
    if(binarySearch(arr,n,key)==-1) cout<<"Given key not found ";
    else cout<<"Given key found and Number of comparison to find given key : "<<binarySearch(arr,n,key);


    return 0;
}
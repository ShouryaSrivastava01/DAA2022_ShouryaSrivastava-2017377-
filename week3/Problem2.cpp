/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.
*/
#include<iostream>
#include<vector>
using namespace std;

 int comparison=0;
 int shift=0;

void selectionSort(vector<int>&nums){
    comparison = 0;
    shift = 0;
     int minIdx;
    for(int i =0;i<nums.size()-1; i++){
        minIdx = i;
        for(int j=i+1;j<nums.size(); j++){
            comparison++;
            if(nums[minIdx]>nums[j]){
                swap(nums[minIdx], nums[j]);
                shift++;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of testcase : ";
    cin>>n;
    while(n--){
    int size; 
    cout<<"Enter the size of the array : ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    selectionSort(arr);
    for(auto i: arr) cout<<i<<" ";
    cout<<"\n";
    cout<<"Comparison : "<<comparison<<endl;
    cout<<"Shifts : "<<shift<<endl;
    }
}
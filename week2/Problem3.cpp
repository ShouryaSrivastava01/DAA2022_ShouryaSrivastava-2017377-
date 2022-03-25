/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given an array of non-negative, design a linear algorithm and implement it using a program to find 
whether key element is present or not and also find total number of comparison.
*/
#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>&nums){
     for(auto i:nums) cout<<i<<" ";
        cout<<"\n";
}

int selectionSort(vector<int>&nums){
    int minIdx;
    //to count the number of comparison
    int cmp=0;
    for(int i =0;i<nums.size()-1; i++){
        minIdx = i;
        for(int j=i+1;j<nums.size(); j++){
            // if any element is less than minIdx element swap
            if(nums[minIdx]>nums[j]){
                swap(nums[minIdx], nums[j]);
                cmp++;
            }
        }
    }
    return cmp;
}

int main(){
    int n; 
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"No of comparison : "<< selectionSort(arr)<<endl;
    for(int i:arr) cout<<i<<" ";
}
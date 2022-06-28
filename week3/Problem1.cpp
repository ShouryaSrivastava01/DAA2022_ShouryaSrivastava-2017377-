/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts total
number of times the array elements are shifted from their place) required for sorting the array.
*/
#include<iostream>
#include<vector>
using namespace std;

 int comparison=0;
 int shift=0;

void display(vector<int>&nums){
     for(auto i:nums) cout<<i<<" ";
        cout<<"\n";
}

void insertionSort(vector<int>&nums){
    comparison=0;
    shift = 0;
    int temp, j;
    for(int i=1; i<nums.size(); i++){
        temp = nums[i];
        j = i-1;
        int cmp = 0;
        comparison++;
        // find the suitable position of temp in sorted part of list
        while(j>=0 && nums[j]>temp){
                nums[j+1] = nums[j];
                j--;
                cmp++;
                shift++;
        }
        nums[j+1] = temp;
        comparison+=(cmp>0)? cmp-1 : 0;

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
    insertionSort(arr);
    for(auto i: arr) cout<<i<<" ";
    cout<<"\n";
    cout<<"Comparison : "<<comparison<<endl;
    cout<<"Shifts : "<<shift<<endl;
    }
}
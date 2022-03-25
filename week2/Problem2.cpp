/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  WAP to implement insertion sort and also find total number of comparison.
*/
#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>&nums){
     for(auto i:nums) cout<<i<<" ";
        cout<<"\n";
}

int insertionSort(vector<int>&nums){
    int temp, j;
    // to count number of comparsion
    int cmp=0;
    for(int i=1; i<nums.size(); i++){
        temp = nums[i];
        j = i-1;
        // find the suitable position of temp in sorted part of list
        while(j>=0 && nums[j]>temp){
            if(nums[j]>temp){
                nums[j+1] = nums[j];
                j--;
                cmp++;
            }
        }
        nums[j+1] = temp;

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
    cout<<"No of comparison : "<< insertionSort(arr)<<endl;
    for(int i:arr) cout<<i<<" ";
}
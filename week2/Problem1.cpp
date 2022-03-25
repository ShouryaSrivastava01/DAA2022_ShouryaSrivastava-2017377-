/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  WAP to implement bubble sort and also find total number of comparison.
*/
#include<iostream>
#include<vector>
using namespace std;

int  bubbleSort(vector<int>&nums){
    // to count the number of comparison
    int cmp=0;
    // to check if the array is sorted and no further comparison needs to be made
    bool flag = false;
    
    for(int i=0;i<nums.size()-1; i++){
        flag = false;
        for(int j=0; j<nums.size()-1-i; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j+1]);
                cmp++;
                flag = true;
            }
        }
        // if no swapping is performed => array is sorted then break the loop
        if(!flag) break;
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
    cout<<"No of comparison : "<< bubbleSort(arr)<<endl;
    for(int i:arr) cout<<i<<" ";
}
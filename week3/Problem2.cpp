/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given a sorted array of positive integers design an algorithm and implement it using a program to find three indices i, j , k such that arr[i] + arr[j] = arr[k]

/* Algorithm
1. Using two pointer approach, define a target and find pair which sum up to the target
2. Traverse from last index to 0th index
3. Define target as arr[current index] and  search pair in range [0 - (current index -1 )]
*/

#include<iostream>
#include<vector>
using namespace std;

// function to find pair which sum up to target
bool twoSum(vector<int>&nums, int i){
    int target = nums[i];

    // using two pointer approach since array is sorted
    int a = 0, b = i-1;
    while(a<=b){
        if(nums[a]+nums[b]==nums[i]){
            cout<<a<<" "<<b<<" "<<i<<endl;
            return true;
        }
        else if(nums[a]+nums[b]>nums[i]) b--;
        else a++;
    }
    return false;
}

// find the triplet
void findTriplet(vector<int>&nums){
    int i;
    int n = nums.size();
    for(i = n-1; i>=0; i--){
        if(twoSum(nums,i)) return;
    }
    cout<<"No sequence found"<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of test cases : ";
    cin>>n;
    while(n--){
        int s;
        cout<<"Enter the size of array : ";
        cin>>s;
        vector<int> arr(s);
        for(int i=0; i<s; i++){
            cin>>arr[i];
        }
       findTriplet(arr);
    }
}
/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given a array of non-positive integers design an algorithm and implement it using a program to count the number of pairs of integers such that their difference is equal to a given key K

/* Algorithm
1. Insert all the element is a hash set.
2. Traverse the array from start
3. If there exit a value in set which is either equal to (target - element) or (target + element ), then increment the count by 1
*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countPair(vector<int>&nums, int target){
    // insert the element in hash set
    unordered_set<int> set(nums.begin(), nums.end());
   
    int cnt = 0;
    for(int i=0;i<nums.size(); i++){
        // target+num or target-num is present in set then cnt++
        if(set.find(target+nums[i])!=set.end() || set.find(target-nums[i])!=set.end() ) 
            cnt++;
    }
    return cnt;
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
        int target;
        cout<<"Enter the target : ";
        cin>>target;
        cout<<countPair(arr, target)<<endl;
    }
}
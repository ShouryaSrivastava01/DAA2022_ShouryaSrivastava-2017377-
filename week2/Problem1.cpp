/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  Given a sorted array of positive integers containing few duplicate elements. Design an algorithm and implement it using a program to find whether the given key element is present int the array or not. If present, then also find the number of copies of given key. (Time complexity : O(logn))
*/

/* Algorithm
1. Using binary search, find  the first occurrence of the given key
2. If first is not found then given key is not present
3. ELSE Using binary search, find the last occurrence of the given key
4. copies of given key = last occurence - first occurrence + 1 
*/

#include<iostream>
#include<vector>
using namespace std;

void findDuplicate(vector<int>& nums, int target){
    int left = 0, right = nums.size()-1;

    int first = -1 , last = -1;

    //find the first occurence of the target 
    while(left<=right){
        int mid = left+ (right - left)/2;
        if(nums[mid]==target){
            first = mid;
            right = mid -1;
        }
        else if(nums[mid]>target) right  = mid - 1;
        else  left = mid +1;
    }

    // if no first occurrence is found then key is not present
    if(first == -1){
        cout<<"KEY NOT Present"<<endl;
        return;
    }
    
    // find the last occurrence
    left = 0, right = nums.size()-1;
    while(left<=right){
        int mid = left+ (right - left)/2;
        if(nums[mid]==target) {
            last = mid;
            left = mid + 1;
        }
       else if(nums[mid]>target) right  = mid - 1;
        else  left = mid +1;
        
    }
    
    cout<<target<<" - "<<last-first+1<<endl;
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
        cout<<"Enter the key to be searched : ";
        cin>>target;

        findDuplicate(arr, target);
        
    }
}

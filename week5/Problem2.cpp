/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))
*/


#include <iostream>
#include<vector>
using namespace std;


void mergeSort(vector<int>&nums, int, int);
void merge(vector<int>&nums, int , int , int);


int main()
{
    int n;
    cout<<"Enter the number of testcases : ";
    cin>>n;
    while(n--){
    int size, key;
    cout<<"Enter the size of the array : ";
    cin>>size; 
    vector<int> arr(size);
    for(int i=0; i<size; i++) cin>>arr[i];
    cin>> key;
    //sort the array
    mergeSort(arr, 0, size-1);
    int p1=0, p2 = size-1;   //two pointer approach
    while(p1<p2){
        if(arr[p1]+arr[p2]==key){
            cout<<arr[p1]<<" "<<arr[p2]<<endl;
            break;
        }
        else if(arr[p1]+arr[p2]>key) p2--;
        else p1++;
    }
    if(p1>=p2) cout<<"No Such Element Exits"<<endl;

}
    return 0;
}

void merge(vector<int>&a,int lb,int mid,int up ){
   int n1 = mid - lb + 1, n2 = up - mid;
   int i = 0, j = 0, k = lb;
   vector<int> left(n1), right(n2);
   for(i=0; i<n1; i++) left[i]= a[i+lb];
   for(i=0; i<n2; i++) right[i]= a[i+mid+1];

   i = 0;
   j = 0;
   while(i<n1 && j<n2){
       if(left[i]<=right[j]) a[k++] = left[i++];
       else a[k++] = right[j++];
            

   }
   while(i<n1) a[k++] = left[i++];
   while(j<n2) a[k++] = right[j++];

}

void mergeSort(vector<int>&a,int lb,int up){
    int mid=(lb+up)/2;
    if(lb<up){
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,up);
        merge(a,lb,mid,up);
    }
}
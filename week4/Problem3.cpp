/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array.
*/


/*
Merge sort
1. START
2. Find the middle index of the array 
    mid <- left + (right – left)/2
3. Divide the array from the middle
4. Call merge sort for the first half of the array
    mergeSort(array, left, mid)
5. Call merge sort for the second half of the array.
    mergeSort(array, mid+1, right)
6. Merge the two sorted halves into a single sorted array. 
    mergeArray(arr, left, mid, right)

Merging of two sorted array
1. START
2. Create two temporary array left and right of size 
    n1 <- mid - left +1
    n2 <- right - left
3. i <- 0, j <- 0, k <- left
4. compare the elements of left array and right array. If left[i]>=right[j], 
    then 
        1. insert right[j] in array at kth index
        2 increment k and j by 1
        3. update inversion by mid - (left+i) +1
    Else
        1. insert left[i] in array at kth index
        2. increment k and i by 1
5. repeat step 3 till i<n1 AND j<n2
6. if any array is left then insert the element in the array and increment k by 1
7. END

*/

#include <iostream>
#include<vector>
using namespace std;


// helper function to partition the array around a pivot element
int partition(vector<int>&, int, int); 
int quickSelect(vector<int>&, int, int, int);



int main()
{
    cout<<"Kth Smallest Element "<<endl;
    int n;
    cout<<"Enter the number of testcases : ";
    cin>>n;
   
   while(n--) {
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size; 
    vector<int> arr(size);
    cout<<"Enter the elements : ";
    for(int i = 0; i<size; i++) cin>>arr[i];
    int k;
    cin>>k;
    int ans = quickSelect(arr, 0, size-1, k);
    if(ans<INT_MAX) cout<<ans<<endl;
    else cout<<"Not present"<<endl;
}
    return 0;
}

int partition(vector<int>&arr, int low, int high){
    
     int pivot = arr[high], i = low;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
    
}

int quickSelect(vector<int>&arr, int low, int high, int k){
    
    while(k>0 && k<= high- low +1){
        int p = partition(arr, low, high);
        
        if (p- low == k - 1)
            return arr[p];
 
        if (p - low > k - 1)
            return quickSelect(arr, low, p - 1, k);
 
        return quickSelect(arr, p + 1, high,
                            k - p+ low - 1);
    }
    return INT_MAX;
}


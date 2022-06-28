/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement : Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it.
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





int main()
{
    int n;
    cout<<"Enter the number of testcases : ";
    while(n--){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size; 
    vector<char> arr(size);
    vector<int> freq(26,0);
    cout<<"Enter the elements : ";
    for(int i = 0; i<size; i++){ 
        cin>>arr[i];
        // treating uppercase and lowercase alphabet as same entity
        if(arr[i]>='a' && arr[i]<='z') freq[arr[i]-'a']++;
        else freq[arr[i]-'A']++;
    }
    
    int max = 0;
    for(int i=0; i<26; i++){
        if(freq[i]>0 && freq[i]>freq[max]) max = i;
    }
    if(freq[max ]== 1) cout<<"No duplicate element"<<endl;
    else cout<<char(max+'a')<<"-"<<freq[max]<<endl;

   }

    return 0;
}
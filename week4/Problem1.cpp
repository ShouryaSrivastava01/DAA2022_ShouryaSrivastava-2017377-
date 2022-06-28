/*
Name : Shourya Srivastava
University Roll NO : 2017377
Section : CE
Problem Statement : Implement merge sort
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
#include <vector>
using namespace std;

int inversion = 0;
int cmp = 0;

void mergeArray(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // number of element in left array
    int n2 = right - mid;    // number of elements in right array

    vector<int> l(n1);
    vector<int> r(n2);
    int i, k, j;
    for (i = 0; i < n1; i++)
        l[i] = arr[left + i]; // temporary left array
    for (i = 0; i < n2; i++)
        r[i] = arr[mid + 1 + i]; // temporary right array

    // merging of two sorted array i.e left and right array
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        cmp++;
        if (l[i] <= r[j])
            arr[k++] = l[i++];
        else
        {
            // number of inversions
            // mid - (left + i) + 1  : number of inversions to be made to swift element from right array to its correct position in the array
            inversion += mid - (left + i) + 1;
            arr[k++] = r[j++];
        }
    }

    while (i < n1)
        arr[k++] = l[i++];
    while (j < n2)
        arr[k++] = r[j++];
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArray(arr, left, mid, right);
    }
}

int main()
{
    int n, size;
    cout << "Enter the number of testcases : ";
    cin >> n;
    while (n--)
    {
        cout << "Enter the size of the array : ";
        cin >> size;
        vector<int> arr(size);
        cout << "Enter the elements : ";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
        cmp = 0;
        inversion = 0;
        mergeSort(arr, 0, arr.size() - 1);
        for (auto i : arr)
            cout << i << " ";
        cout << "\n";

        cout << "No of comparison : " << cmp << endl;
        cout << "No of inversion : " << inversion << endl;
    }
    return 0;
}
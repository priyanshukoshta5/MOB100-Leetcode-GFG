//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        swap(arr[0], arr[i]);
        
        int last = i;
        int j = 0;
        while(j < last)
        {
            if((j*2 + 1) < last && arr[j*2 + 1] > arr[j])
            {
                if((j*2 + 2) < last && arr[j*2 + 2] > arr[j] && arr[j*2 + 2] > arr[j*2 + 1])
                {
                    swap(arr[j], arr[j*2 + 2]);
                    j = j*2 + 2;
                }
                else
                {
                    swap(arr[j], arr[j*2 + 1]);
                    j = j*2 + 1;
                }
            }
            else if((j*2 + 2) < last && arr[j*2 + 2] > arr[j])
            {
                swap(arr[j], arr[j*2 + 2]);
                j = j*2 + 2;
            }
            else
                break;
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = 0; i < n; i++)
        {
            int prev = i;
            int cur = (i-1) / 2;
            while(prev > 0 && arr[cur] < arr[prev])
            {
                swap(arr[cur], arr[prev]);
                prev = cur;
                cur = (cur - 1) / 2;
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for(int i = n-1; i >= 0; i--)
        {
            heapify(arr, n, i);
            // for(int j = 0; j < n; j++)
            //     cout<<arr[j]<<" ";
            // cout<<endl;
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends
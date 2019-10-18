#include<bits/stdc++.h>
using namespace std;
// Function to Insert an element into the Heap
void insert(vector<int> &tree, int n, int item)
{
	n = n+1;
	int ptr = n-1;
	tree[ptr] = item;
	while(ptr)
	{
		int par = floor((ptr-1)/2);
		// start from the leaf and go up to the root until heap property is not violated
		if(tree[ptr] > tree[par]) swap(tree[ptr],tree[par]);
		ptr = par;
	}
	
}
//Function to delete an element from the Heap and store the value into Item
void del(vector<int> &tree, int n, int &item)
{
	item = tree[0];
	int last = tree[n-1];
	int ptr = 0;
	int left = 1, right = 2;
	/* Start from the root and go down in top down manner until the heap property is not violated*/
	while(right<n)
	{
		// Correct position of last element of the array is found
		if(last>=tree[left] && last>=tree[right])
		{
			tree[ptr] = last;
			return;
		}
		// Check whether the left one is greater or right, we go to the higher one
		if(tree[right]<=tree[left])
		{
			tree[ptr] = tree[left];
			ptr = left;
		}
		else
		{
			tree[ptr] = tree[right];
			ptr = right;
		}
		left = 2*ptr + 1;
		right = 2*ptr + 2;
	}
	// check whether the last element goes to the last node of the heap or not
	if(left==n-1 && last<tree[left]) ptr = left;
	tree[ptr] = last;
}
//Function to implement the heap sort algorithm
void heapsort(vector<int> &A, int N)
{
	/* First we insert all the elements in such a way that the given array is in heap form */ 
	for(int j=0;j<N;++j) insert(A,j,A[j]);
	int j = N;
	while(j)
	{
		int item;
		//We repeatedly delete the root of the heap and store the value at the end of the heap.
		del(A,j,item);
		//j-1 is the index of the element which is at it's correct place in sorted order
		A[j-1] = item;
		// We iteratively decrease the size of the heap and increase the size of the sorted array from back of the array
		j--;
	}
}
int main()
{
	vector<int> A = {10,20,15,30,40,5,2,5,2,3};
	heapsort(A,A.size());
	for(int i=0;i<A.size();++i) cout<<A[i]<<" ";
	cout<<endl;
	
	
}



void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
      int k = i;
      int l = 2*k + 1;
      int r = 2*k + 2;
      while(r<n)
      {
          if(arr[k] >= arr[l] && arr[k] >= arr[r]) break;
          if(arr[r]>arr[l])
          {
              swap(arr[r],arr[k]);
              k = r;
          }
          else
          {
              swap(arr[l],arr[k]);
              k = l;
          }
          l = 2*k + 1;
          r = 2*k + 2;
      }
      if(l < n)
      {
          if(arr[l] > arr[k])
          {
              swap(arr[l],arr[k]);
          }
      }
}
// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    for(int i=0;i<n;++i)
    {
        int j = i;
        while(j!=0)
        {
            int par = (j-1)>>1;
           // if(arr[par] >= arr[j]) break;
            if(arr[par] < arr[j]) swap(arr[par],arr[j]);
            j = par;
        }
    }
}

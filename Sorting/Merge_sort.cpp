#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int arr1[n1];
	int arr2[n2];
	for (int i = 0; i < n1; i++)
		arr1[i] = arr[low + i];
	for (int i = 0; i < n2; i++)
		arr2[i] = arr[mid + 1 + i];
	int i = 0, j = 0, k = low;
	while (i < n1 && j < n2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
			k++;
		} else
		{
			arr[k] = arr2[j];
			j++;
			k++;
		}
	}
	while (i < n1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {10, 5, 1, 45, 9, 12};
//10 30 20 40 10 20
	int low = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	int high = n - 1;
	merge_sort(arr, low, high);

	for (auto x : arr)
		cout << x << " ";

	return 0;
}


//Merge sort.....stable algorithm
//O(nlogn)..best,average,worst case
//theta n work for logn +1 times..(tree height)
//Not a in place algorithm..mtlb requires 2 arrays(extra)
//Space complexity of merge sort is O(n) or theta n..why??
//logn times it will be using theta(n) space..
//to bhai one point of time mein any only one side calls in function call
//stack
//Quick sort is in place...recursive fun call stack to h hi..
//but is tail recursive
//Not a tail recursive algorithm..last line is not recursive call..in
// merge sort

//for larger values data sets..1% merge sort may work better..because
//quick sort
//worst case time complexity is O(n2)
//for smaller value datasets..quick sort is better
//there is advanced quick sort which works in O(1) space

//Average case of quick sort is O(nlogn)..worst case is n2
//In place algorithm
//tail recursive algorithm

//In c++
//sort in stl uses intro sort(hybrid of quick sort,heap sort n insertion sort)
//majorly quick sort
//yeah but for c++ stl stable_sort(), merge_sort is used
//c mein q_sort is for quick sort

//in merge sort merge function is complex
//In quick sort the parition function is more complex
//quick sort has 3 types of partition
//Naive
//Lomuto
//Hoare

//the naive partition is stable sorting..but requires 3 traversals
//which is why it is no good..merge sort better
//the Hoare partition of the other 2 is most efficient..works in
//O(n)...one traversal

//definitely quick sort is faster...
//but is not stable
//for stability..go with merge_sort

//else go with quick_sort variation i.e., intro sort c++
//as quick sort worst case is bad.

//merge sort..pace is theta(n)fun call stack + theta n for array
//quick sort best case space si theta logn
//worst case theta n..fun call stack

//hoarse partition
#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;
	while (true)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j) return j;
		else
			swap(arr[i], arr[j]);
	}
}

void q_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		q_sort(arr, low, p);
		q_sort(arr, p + 1, high);
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
	int low = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	int high = n - 1;
	q_sort(arr, low, high);

	for (auto x : arr)
		cout << x << " ";

	return 0;
}



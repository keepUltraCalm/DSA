//Q. Print the maximum difference between elements of the array??
//   Array cannot be sorted..i.e., ans should be acc to original array
// and j>i such that arr[j]-arr[i] is maximum

//OR the problem can be called as

//Leetcode BEST TIMe TO BUY AND SELL STOCKS I

//You can only buy and sell stocks once.

//Brute-force approach
/*
Generate all pairs of arr[i],arr[j], j>i, using n^2 loop
calculate which one gives you maximum value
Time : O(n^2)
Space : O(1)
*/

//Better
/*
Maintain an array of same size. Start from right, go to left and store the 
maximum element that far.
Run another loop for original array, calculate diff and update max variable
Time : O(n) -> two traversals
Space : O(n)
*/

//Optimal sol
/*
Maintain the minimum element from left to right
Check if curr - minimum give you >res
then update min_value if it was smaller than the above minimum
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void max_diff(int arr[], int n) {
    int res = arr[1] - arr[0];
    //it will store the maximum difference 
    int min = arr[0];
    //this will store minimum element for upcoming elements
    for (int i = 1; i < n; i++) {
        if (arr[i] - min > res)
            res = arr[i] - min;
        if (arr[i] < min)
            min = arr[i];
        //this line is written later because if it was minimum
        //still it can't be used because j>i such that arr[j]-arr[i] is max
        //i.e., same element can't be taken.
    }
    cout << res;
}

int main() {

    cout << fixed;
    cout << setprecision(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    max_diff(arr, n);

    // for (auto x : arr)
    //     cout << x << " ";

    return 0;
}

//Complexity Time: Theta(n)
//Space O(1)

//O/P
/*
8
*/

//find which number has highest frequecy in given ranges
/*
Highest frequency element in given ranges

Naive way..use a unordered_map..count every element frequencies
O(n*m)..n size of arr, m-range

we can do better if element range is small like <1000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int sol(int arr1[], int arr2[], int n) {
    int arr3[1000] = {0}; //999 > max element in both arrays
    for (int i = 0; i < n; i++) {
        ++arr3[arr1[i]];
        --arr3[arr2[i] + 1];
    }
    // for (auto x : arr3)
    //     cout << x << " ";
    int max = INT_MIN;
    arr3[0] = 0;
    for (int i = 1; i < 8; i++) {
        arr3[i] = arr3[i - 1] + arr3[i];
        if (arr3[i] > max)
            max = arr3[i];
    }
    return max;
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

    int arr1[] = {1, 2, 3};
    int arr2[] = {3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << sol(arr1, arr2, n);

    return 0;
}

/*
O/P 3
*/

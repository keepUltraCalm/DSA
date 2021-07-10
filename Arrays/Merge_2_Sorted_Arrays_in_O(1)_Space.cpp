//Merge 2 sorted arrays in O(1) space
/*
Brute:
Create another array n1 + n2
n= n1+n2
n1..size of ist
n2..size of 2nd
add the elements in the array
sort the array
then add elements back int the two arrays
Time: O(nlogn + n + n)
Space: O(n)

Optimal Solution:
Use in-place sorting
if your arr1 element is more, swap it with arr2[0]
so you will get your min element at its correct position
because the arrays are sorted
and then put that swapped element on correct position in arr2

Time: O(n1*n2) you will traverse in first array..
and maintain the correct order by using O(n2) loop in arr2
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

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

    int arr1[] = {3, 5, 6, 8, 12};
    int arr2[] = {1, 4, 9, 13};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    //cout << m << " ";
    int n = sizeof(arr2) / sizeof(arr2[0]);
    //cout << n << '\n';
    for (int i = 0; i < m; i++) {
        if (arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            int temp = arr2[0];
            int k;
            for (k = 1; k < n; k++) {
                if (temp > arr2[k]) {
                    arr2[k - 1] = arr2[k];
                    arr2[k] = temp;
                }
            }
        }
    }
    for (auto x : arr1)
        cout << x << " ";
    cout << '\n';
    for (auto x : arr2)
        cout << x << " ";
    cout << '\n';


    return 0;
}

/*
O/P

1 3 4 5 6
8 9 12 13


Time: O(n1*n2)..n1=size of 1st array, n2=size of 2nd array
Space: O(1)
*/

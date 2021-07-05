//Q. Move zeros to the end while maintaining original order of the array

//Brute
/*
Find a zero..
traverse its right, find a non-zero
and swap both
Time complexity is clearly 0(n^2)
*/

//Optimal Sol

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void move_zeros(int arr[], int n) {
    int count = 0;
    //maintain a count of the non-zero numbers
    //arr_index +1 = count, because we know before this index all elements
    //are non-zero
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
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

    int arr[] = {0, 10, 0, 8, 12, 0, 0, 45, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    move_zeros(arr, n);

    for (auto x : arr)
        cout << x << " ";

    return 0;
}

//Complexity Time: O(n)
//Space O(1)

//O/P
//10 8 12 45 0 0 0 0 0 0 

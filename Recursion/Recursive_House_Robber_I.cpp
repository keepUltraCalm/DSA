//Recursive house robber I
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int sol(int arr[], int n) {
    if (n < 1)
        return 0;
    if (n == 1)
        return arr[0];
    return max((arr[n - 1] + sol(arr, n - 2)), (sol(arr, n - 1)));
  //either the prev res, or take this + prev prev result
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

    int arr[] = {1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = sol(arr, n);
    cout << ans;


    return 0;
}

//dp house robber II
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int sol(int arr[], int n) {
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[n - 1];
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

    int arr[] = {1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (n < 1)
        cout << "0";
    if (n == 1)
        cout << arr[0];
    if (n == 2)
        cout << max(arr[0], arr[1]);
    if (n > 2) {
        //if you handle above cases in sol() if n==1 sol(arr+1,n-1)
        //arr+1 will be problem
        //note sol(arr+1,n) prints 2 3 1 1 that's why arr+1,n-1 taken
        int res = max(sol(arr, n - 1), sol(arr + 1, n - 1));
        cout << res;
    }


    return 0;
}

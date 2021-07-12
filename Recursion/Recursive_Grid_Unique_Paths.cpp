//Recursive grid unique paths
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int sol(int m, int n, int count) {
    if (m == 0 || n == 0)
        return 0;
  //ofcourse 0
    if (m == 1)
        return 1;
    if (n == 1)
        return 1;
  //only 1 possible
    return sol(m - 1, n, ++count) + sol(m, n - 1, ++count);
  //increase count..add both choices
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

    int m = 7, n = 3;
    int count = 0;
    cout << sol(m, n, count);

    return 0;
}

//O/P  28
/*
TIme: O(2^n + 2^n-1)..exponential
*/

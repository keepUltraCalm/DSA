
/*
PREFIX SUM
Check if the given array can be divided into 3 continuous arrays of equal sum
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void sol(int arr[], int n) {
    if (n < 3) {
        cout << "Not possible";
        return;
    }
    else if (n == 3) {
        if (arr[0] == arr[1] == arr[2]) {
            cout << "Sum: " << arr[0];
            return;
        } else {
            cout << "Not possible";
            return;
        }
    }
    else {
        int p[n] = {0};
        p[0] = arr[0];
        for (int i = 1; i < n; i++)
            p[i] = p[i - 1] + arr[i];
        // for (auto x : p)
        //     cout << x << " ";
        int l = 0, l1 = 1, h1 = n - 2, h = n - 1;
        while (l1 < h1) {
            if (p[l1] == p[h] - p[h1] + arr[h1] && p[l1] == p[h1] - p[l1] - arr[h1] ) {
                cout << "Sum: " << p[l1];
                return;
            } else {
                if (p[l1] <= p[h] - p[h1] + arr[h1])
                    ++l1;
                else
                    --h1;
            }
        }
        return;
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

    int arr[] = {5, 2, 6, 1, 1, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol(arr, n);


    return 0;
}

/*
O/P
Sum: 7
*/

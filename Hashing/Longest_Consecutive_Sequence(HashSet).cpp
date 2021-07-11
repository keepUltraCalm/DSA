//LONGEST CONSECUTIVE SEQUENCE
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

    int arr[] = {102, 4, 100, 1, 101, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    set<int>s;
    int maxx = 0;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    for (int i = 0; i < n; i++) {
        if (!s.count(arr[i] - 1)) {
            int curr = 1;
            while (s.count(arr[i] + 1)) {
                /*
                find can only be used for 1 search..because
                the itertor will change to .empty() if element not found
                count can be used in loop to tell is element present or not
                */
                ++curr;
                ++arr[i];
            }
            maxx = max(curr, maxx);
        }
    }
    cout << maxx;


    return 0;
}

/*
O/P
4

Time: O(n + n + O(1)*n for finding)..we will run O(n) when we get minimum element
Space: O(n)
*/

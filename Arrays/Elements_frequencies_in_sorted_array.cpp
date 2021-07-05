//Q. Print the frequencies of all elements in a sorted array??
/*
Q is easy, implementation is tricky
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void frequencies(int arr[], int n) {
    int count = 1;
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            ++count;
            //if last element same as second last
            //we just increment count
        }
        else {
            cout << arr[i - 1] << " " << count << '\n';
            count = 1;
            //we are printing the before element
            //we didn't print last element if it was not
            //same as second last
            //changed count to 1
        }
    }
    if (i == n)
        cout << arr[i - 1] << " " << count << '\n';

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

    int arr[] = {10, 10, 10, 25, 30, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    frequencies(arr, n);

    // for (auto x : arr)
    //     cout << x << " ";

    return 0;
}

//Complexity Time: Theta(n)
//Space O(1)

//O/P
/*
10 3
25 1
30 2
*/

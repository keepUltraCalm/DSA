//Q. Frequencies of all elements in an unsorted array

/*
Naive:
suppose we are on index i in array
Now,check on the left..have we already printed this element with its frequency
if not..means its a unique element
so go to its right and increment its occurence count and print
Time: O(n^2)
Space : O(1)

Efficient:
Use a hashmap..unordered_map in c++
check for curr..is it already present
++its occurence
hashmap key is arr[i], value is its occurence
else
add it
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

    int arr[] = {50, 50, 10, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++) {
        ++myMap[arr[i]];
        //if present it will increase key's value by 1
        //if not present it will create one key value pair & ++
        //helps in setting key's value to 1
    }
    for (auto x : myMap) {
        cout << x.first << " " << x.second;
        cout << '\n';
    }

    return 0;
}

/*
O/P
40 1
50 2
10 2
order can change it doesn't store in sorted order
to save time we use this

Time: O(n) + O(n)for traversing myMap
O(1) ++operation on map(unordered)
Space: O(n)
*/

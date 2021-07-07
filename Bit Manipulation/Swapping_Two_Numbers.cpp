
//Q. SWAP NUMBERS WITHOUT USING EXTRA SPACE

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

    int a = 5, b = 7;
    //I want ot swap them
    /*
    1. save your time

    swap(a, b);
    cout << a << " " << b;
    */

    /*
    2. use temp variable
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b;
    */

    /*
    3. don't like that!!!!!
     a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b;
    */

    /*
    4. elite level people method
    */
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b;
    //😎😎

    return 0;
}

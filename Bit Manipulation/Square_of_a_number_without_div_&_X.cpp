//square of a number using bits..without multiply & /

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int square(int n) {
    /*
    if n odd..then it can be written as 2*x +1
    even 2*x
    x = floor(n/2) which is n>>1(  >>1 divides by 2power1) left multiplies
    4x^2 can be said as x^2 << 2 ( x^2 multiply by 4)
    */
    if (n == 0)
        return 0;
    if (n < 0)
        n = -n;
    int x = n >> 1;
    if (n & 1 != 1)
        return (square(x) << 2);
    else
        return (square(x) << 2 + x << 2 + 1);// (2x+1)^2

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

    int n = 5;
    cout << square(n);



    return 0;
}


//Time : O(logn) everytime in recursion /2 for x
//Space: logn function calls

//FIND THE MOST SIGNIFICANT BIT(left most set bit in a number) in O(1)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int msb(int n) {
    /*
    8 in binary 1 0 0 0
    log2(n) will give you what..3..what is 3?
    log2(n)=k  so n is 2^k so k=3
    now 1 means 0 0 0 1
    shift it 3 times..you get your ans
    */
    int k = (int)log2(n);
    return 1 << k;
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

    int n = 273;
    cout << msb(n);


    return 0;
}

/*
O/P
256
*/
//Time : O(1)

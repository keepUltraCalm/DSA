#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void permute(string s, int i) {
    if (i == s.length() - 1) {
        cout << s << '\n';
        return;
      //base case
    }
    for (int j = i; j < s.length(); j++) {
        swap(s[i], s[j]);
        permute(s, i + 1);
        swap(s[i], s[j]);
      //swap to avoid code breaking
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

    string s = "ABC";
    int i = 0;
    permute(s, i);
    return 0;
}

//O/P
/* 
ABC
ACB
BAC
BCA
CBA
CAB
*/

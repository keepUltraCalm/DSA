//no. of occurences of one string in another
#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main()
{
    cout << fixed;
    cout << setprecision(2);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    string s1 = "bazanaz";
    string s2 = "na";
    string s3 = s1;
    int n = 0;
    int count = 0;
    bool res = true;
    for (int i = 0; i < s3.length(); i++) {
        if (s3.find(s2) != string::npos) {
            n = s3.find(s2) + s2.length();
            s3 = s3.substr(n, s3.length() - n);
            ++count;
        } else {
            res = false;
            break;
        }
    }
    if (res)
        cout << count;
    else
        cout << "-1";

    return 0;
}



/*
cd > aab   no
in string sorting also   no
*/


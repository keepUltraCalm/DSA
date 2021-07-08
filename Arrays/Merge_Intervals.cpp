/*
Leetcode : MERGE INTERVALS or
MERGE OVERLAPPING SUBINTERVALS

Brute:
O(n^2) check for all
approach:
first take an interval..check on its right
does any overlap happen
if yes..change the interval..store it in data structure
now increase i by 1
now you are on second pair..check if it lie in the range stored in your ds
if yes i++
if no, check on its right..

OPTIMAL Sol:
below
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

vector<pair<int, int>> merge(vector<pair<int, int>> &v) {
    vector<pair<int, int>> res;
    if (v.size() < 1)
        return res;
    //edge case

    sort(v.begin(), v.end());
    //sort your vector
    pair<int, int>y = {v[0].first, v[0].second};
    res.push_back(y);
    int c = 0;
    //push the first pair and store its index in c
    for (int i = 1; i < v.size(); i++) {
        if (res[c].second >= v[i].first) {
            //lets take an ex
            /*
            1 5 and 3 6 just check is 5>=3 if yes, merge..
            else
            push this interval in vector & c++
            */
            res[c].second = v[i].second;
        } else {
            res.push_back(v[i]);
            c++;
        }
    }
    return res;
}

// vector<int> ans(vector<int> & x) {
//     return x;
// }
//this works

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

    vector <pair<int, int >> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    //vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    //size of this vector is 4

    vector<pair<int, int>> ans = merge(v);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second;
        cout << '\n';
    }

    // vector<int> x = {4, 5};
    // vector<int> res = ans(x);
    return 0;
}

/*O/P
1 6
8 10
15 18
*/


//Time : O(nlogn + n)
//Space : O(n) max size of returned vector
// Although can be ignored ,its auxiliary space..because can be printed also


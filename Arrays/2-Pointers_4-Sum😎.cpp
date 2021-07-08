//Q Leetcode - 4 SUM
/*

FIND ALL UNIQUE QUADUPLETS WHICH SUM TO TARGET VALUE

Brute force
You got it.. O(n^4)
generate all

Better sol
This question's better sol is where you are very close to the optimal
special😁
So, what's the approach
Sort + 3-pointers + Binary search!!!!..yes
sort the array first
So,first run two nested loops, i=0 to n-1, j=i+1 to n-1...now create a 3rd pointer
k=j+1...now, for 4th get it using binary search...on the right of k
if you find a quad..you store it
move the 3 pointers due the dublicates(as array is sorted)
Time: O(n^3logn + nlogn)
Space: O(m) m = size of vector which stores quads(unique)
*/

/*
Optimal Sol:
1. sort the array
2. run i=0,j=i+1 till n-1
3. don't do a binary search...use left=j+1  right=n-1
4. now proceed the same way like 3-Sum discussed(previous question discussed)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

vector<vector<int>> sol(vector<int> &v, int target) {
    int sum = 0;
    vector<vector<int>> res;
    if (v.size() < 4)
        return res;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            sum = target;
            sum -= (v[i] + v[j]);
            int low = j + 1;
            int high = v.size() - 1;
            while (low < high) {
                if (sum - (v[low] + v[high]) == 0) {
                    vector<int> y;
                    y.push_back(v[i]);
                    y.push_back(v[j]);
                    y.push_back(v[low]);
                    y.push_back(v[high]);
                    res.push_back(y);
                    //for high
                    while (high > low && v[high] == y[3])
                        high--;
                    //for low
                    while (low < high && v[low] == y[2])
                        low++;
                } else if (sum - (v[low] + v[high] > 0)) {
                    low++;
                } else {
                    high--;
                }
            }
            //for j
            while (j + 1 < v.size() && v[j] == v[j + 1])
                j++;
        }
        //for i
        while (i + 1 < v.size() && v[i] == v[i + 1])
            i++;
    }
    return res;
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

    vector<int> v = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> z = sol(v, target);
    for (int i = 0; i < z.size(); i++) {
        for (auto x : z[i])
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}

/*
O/P
1 1 3 4
1 2 2 4
1 2 3 3

Time: O(n^3 + nlogn(sorting))
Space: O(m) m= result vector size(unique quads)
*/


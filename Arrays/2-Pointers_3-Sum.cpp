//Q   FIND all TRIPLETS that sum to 0
//Leetcode :3 sum problem
/*

Brute force:
O(n^3)
find all the triplets...
check if their sum is 0
create a vector of size 3
push the triplets...
push this vector in main vector

Time: O(n^3)
Space O(n)

Better
first create a hashmap of arr[i],occurence no.
do two loops:
check -(a+b) is in map..if yes
but take care to remove hash[arr[i]]-- and hash[arr[j]]--
from the set that time while finding ans
then add them again
create an additional set for ans
push triplets in sorted order in it
O((n^2)*logm)logm because inserting in set(we want unique so used set)
Space O(n+m) for map (n) for set (m)

Optimal
Sort the array
Now go for 2 loops..but for 3rd..we will use 2-pointers..which will use the fact that array is sorted
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

    int arr[] = { -1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        int sum = -(arr[i]);
        int low = i + 1;
        int high = n - 1;
        while (low < high) {
            if (arr[low] + arr[high] < sum) {
                low++;
            } else if (arr[low] + arr[high] > sum) {
                high--;
            } else {
                vector<int> x;
                x.push_back(arr[i]);
                x.push_back(arr[low]);
                x.push_back(arr[high]);
                res.push_back(x);
                //but if there are dublicates now after low
                //before high..we can skip them..below we add the code for this

                //not equal two because we need 2
                //for low duplicates
                while (low < high && x[1] == arr[low]) {
                    low++;
                }
                //for high duplicates
                while (high > low && x[2] == arr[high]) {
                    high--;
                }
            }

        }
        //for i duplicates
        while (i + 1 < n && arr[i] == arr[i + 1])
            i++;
    }
    for (int i = 0; i < res.size(); i++) {
        for (auto g : res[i])
            cout << g << " ";
        cout << '\n';
    }

    return 0;
}


/*
O/P
-1 -1 2
-1 0 1


Time Complexity: O((n^2) + nlogn)
Space Complexity: O(m) where m= res vector size
*/


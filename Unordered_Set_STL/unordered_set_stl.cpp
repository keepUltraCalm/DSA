#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

//set create
	unordered_set<int> mySet;

//insert
	mySet.insert(45);
	mySet.insert(40);
	mySet.insert(35);

//accessing the set
	for (auto x : mySet) {
		cout << x << " ";
	}
	cout << '\n';

	for (auto it = mySet.begin(); it != mySet.end(); it++) {
		cout << *it << " ";
	}
	cout << '\n';

//find
	if (mySet.find(45) != mySet.end()) {
		cout << "Found" << '\n';
	}
	else
		cout << "Not found" << '\n';

//erase
	mySet.erase(45);

//set size
	cout << mySet.size() << '\n';

//clear everything
	mySet.clear();
	cout << mySet.size() << '\n';

	mySet.insert(67);

//empty check
	if (mySet.empty()) {
		cout << "Empty" << '\n';
	} else
		cout << "Not empty" << '\n';

//for multiple find..use count
	if (mySet.count(67))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

/*
35 45 40 
35 45 40 
Found
2
0
Not empty
Yes
*/


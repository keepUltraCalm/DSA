#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

//map key value create
	unordered_map<string, int> myMap;
	myMap.insert(make_pair("geek", 20));
	myMap.insert({"hey", 10});

//insert
	myMap["geek"] = 30;
	//it not only change the key's value but inserts also
	//if the key is not present

//accessing the map
	for (auto x : myMap) {
		cout << x.first << " " << x.second << '\n';
	}

	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		cout << it->first << " " << it->second << '\n';
	}

//find
	if (myMap.find("geek") != myMap.end()) {
		//cout << "Found at " << myMap["geek"] << '\n';
		//or
		cout << "Found at " << myMap.at("geek") << '\n';
	}
	else
		cout << "Not found" << '\n';

//erase in map
	myMap.erase("hey");

//map size
	cout << myMap.size() << '\n';

//clear everything
	myMap.clear();
	cout << myMap.size() << '\n';

	myMap.insert({"Yp", 90});

//empty check
	if (myMap.empty()) {
		cout << "Empty" << '\n';
	} else
		cout << "Not empty" << '\n';

//for multiple find..use count
	if (myMap.count("Yp"))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

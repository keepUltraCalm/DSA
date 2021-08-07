#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	unordered_map<string, vector<string>> mp;
	for (auto x : strs) {
		string ori = x;
		sort(x.begin(), x.end());
		mp[x].push_back(ori);
	}
	for (auto x : mp) {
		for (string y : x.second)
			cout << y << " ";
		cout << '\n';
	}
	return 0;
}

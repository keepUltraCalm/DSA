#include <bits/stdc++.h>
using namespace std;

bool is_subsequence(string s1, string s2) {
	int j = 0;
	int i = 0;
	for (i = 0; i < s2.length();) {
		//above because on finding also we are increasing j
		if (j > s1.length() && i < s2.length())
			return false;
		if (s1[j] == s2[i])
			++i;
		j++;
	}
	return true;
}

int main() {
	string s1 = "ABACDE";
	string s2 = "ACF";
	bool ans = is_subsequence(s1, s2);
	cout << ans;
	return 0;
}

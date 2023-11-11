#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	string s;
	input(s);

	vector<int> v;
	range(i, 0, n - 1) {
		if (s[i] == s[i + 1]) {
			v.push_back(i);
		}
	}

	while (q--) {
		int l, r;
		input(l, r);

		int i = lower_bound(v.begin(), v.end(), l - 1) - v.begin();
		int j = upper_bound(v.begin(), v.end(), r - 2) - v.begin();

		// print(i, j);
		print(max(0ll, j - i));
	}
}

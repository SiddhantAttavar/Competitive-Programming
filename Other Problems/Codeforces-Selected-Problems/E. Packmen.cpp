#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

bool check(string s, int x) {
	int c = 0;
	range(i, 0ll, s.size()) {
		if (s[i] != 'P') {
			continue;
		}

		while (c < s.size() and s[c] != '*') {
			c++;
		}

		if (c >= s.size()) {
			return true;
		}

		if (i - c > x) {
			return false;
		}


		c = max({c, i + max(0ll, x - 2 * max(0ll, i - c)) + 1, i + (x - max(0ll, i - c)) / 2 + 1});
	}

	while (c < s.size() and s[c] != '*') {
		c++;
	}
	return c >= s.size();
}

int32_t main() {
	setup();
	int n;
	input(n);

	string s;
	input(s);

	int l = 0, r = 2 * n, res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(s, m)) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	print(res);
}

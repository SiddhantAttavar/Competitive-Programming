#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

bool check(int n, string s, string t, int k) {
	vector<vector<int>> pref(26, vector<int>(s.size() + 1, 0));
	range(j, 0, s.size()) {
		range(i, 0, 26) {
			pref[i][j + 1] = pref[i][j];
		}
		pref[s[j] - 'a'][j + 1]++;
	}

	int x = 1, y = -1;
	for (char c : t) {
		y++;
		if (y == s.size()) {
			y = 0;
			x++;
		}

		if (pref[c - 'a'].back() == 0) {
			return false;
		}

		int o = k;
		if (pref[c - 'a'].back() - pref[c - 'a'][y] >= o) {
			y = lower_bound(pref[c - 'a'].begin(), pref[c - 'a'].end(), pref[c - 'a'][y] + o) - pref[c - 'a'].begin() - 1;
			continue;
		}

		o -= pref[c - 'a'].back() - pref[c - 'a'][y];
		x++;
		x += o / pref[c - 'a'].back();
		o %= pref[c - 'a'].back();
		if (o == 0) {
			x--;
			o += pref[c - 'a'].back();
		}
		y = lower_bound(pref[c - 'a'].begin(), pref[c - 'a'].end(), o) - pref[c - 'a'].begin() - 1;

		if (x > n) {
			return false;
		}
	}

	return x <= n;
}

int32_t main() {
	setup();

	int n;
	input(n);

	string s, t;
	input(s, t);

	int l = 1, r = 1e18, res = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(n, s, t, m)) {
			l = m + 1;
			res = m;
		}
		else {
			r = m - 1;
		}
	}

	print(res);
}

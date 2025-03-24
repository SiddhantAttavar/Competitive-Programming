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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	while (q--) {
		int i, x;
		input(i, x);
		i--;
		a[i] = x;

		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}

		int y = 0;
		vector<pair<int, int>> v(n + 1, {n, -1});
		for (pair<int, int> p : m) {
			y = max(y, p.second);
			v[p.second] = {min(v[p.second].first, p.first), max(v[p.second].second, p.first)};
		}

		vector<pair<int, int>> w(n + 1, {n, -1});
		for (int i = n - 1; i >= 0; i--) {
			w[i] = {min(v[i].first, w[i + 1].first), max(v[i].second, w[i + 1].second)};
		}

		int res = max(w[1].second - v[y].first, v[y].second - w[1].first);
		rep(a, 0, y + 1) {
			res = max({res, w[y - a].second - v[a].first, v[a].second - w[y - a].first});
		}


		print(res);
	}
}


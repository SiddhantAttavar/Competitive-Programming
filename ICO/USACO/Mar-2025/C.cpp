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

	int n, d;
	input(n, d);

	int a, b;
	input(a, b);

	vector<int> v(n);
	arrput(v);
	sort(v.begin(), v.end());

	vector<int> p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] + v[i];
	}

	int k = d * (a - b);
	rep(i, n - a, n) {
		int l = 1, r = d, y = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			int j = lower_bound(v.begin() + i, v.end(), v[i] + m) - v.begin();
			// print(m, j, i);
			if ((v[i] + m) * (j - i) - (p[j] - p[i]) <= k) {
				y = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		v[i] += y;
		k -= y;
	}
	// arrprint(v);

	int res = 0;
	for (int i : v) {
		res = (res + i * i) % MOD;
	}
	print(res);
}

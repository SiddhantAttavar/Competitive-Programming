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

	int n;
	input(n);

	vector<int> x(n), y(n), r(n);
	rep(i, 0, n) {
		input(x[i], y[i], r[i]);
	}

	int N = 1e4;
	vector<vector<int>> v(N + 1);
	rep(i, 0, n) {
		v[x[i]].push_back(y[i]);
	}
	rep(i, 0, N + 1) {
		sort(v[i].begin(), v[i].end());
	}

	int res = 0;
	rep(i, 0, n) {
		res--;
		rep(j, max(0ll, x[i] - r[i]), min(N, x[i] + r[i]) + 1) {
			int s = 0, e = 200, k = -1;
			while (s <= e) {
				int m = (s + e) / 2;
				if ((x[i] - j) * (x[i] - j) + m * m <= r[i] * r[i]) {
					k = m;
					s = m + 1;
				}
				else {
					e = m - 1;
				}
			}
			res += upper_bound(v[j].begin(), v[j].end(), y[i] + k) - lower_bound(v[j].begin(), v[j].end(), y[i] - k);
		}
	}
	print(res);
}

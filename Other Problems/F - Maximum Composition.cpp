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

	int n, k;
	input(n, k);

	vector<pair<int, int>> v(n);
	rep(i, 0, n) {
		input(v[i].first, v[i].second);
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		return abs(a.first * (b.first + b.second) + a.second) < abs(b.first * (a.first + a.second) + b.second);
	});

	vector<vector<int>> f(n, vector<int>(k + 1));
	vector<vector<int>> g(n, vector<int>(k + 1));
	f[0][0] = g[0][0] = 1;
	f[0][1] = g[0][1] = v[0].first + v[0].second;
	rep(i, 1, n) {
		f[i][0] = 1;
		rep(j, 1, min(k + 1, (int) i + 2)) {
			f[i][j] = max({f[i - 1][j], f[i - 1][j - 1] * v[i].first + v[i].second, g[i - 1][j - 1] * v[i].first + v[i].second});
			g[i][j] = min({g[i - 1][j], f[i - 1][j - 1] * v[i].first + v[i].second, g[i - 1][j - 1] * v[i].first + v[i].second});
		}
	}
	print(f[n - 1][k]);
}

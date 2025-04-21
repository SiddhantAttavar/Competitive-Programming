#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

pair<int, int> dfs(int x, int y, vector<string> &a, vector<vector<bool>> &v) {
	v[x][y] = true;
	pair<int, int> res = {0, 1};
	vector<pair<int, int>> l = {
		{x - 1, y},
		{x + 1, y},
		{x, y - 1},
		{x, y + 1},
	};
	for (pair<int, int> p : l) {
		if (min(p.first, p.second) >= 0 and p.first < a.size() and p.second < a[0].size() and a[p.first][p.second] == '.') {
			if (!v[p.first][p.second]) {
				pair<int, int> q = dfs(p.first, p.second, a, v);
				res.first += q.first;
				res.second += q.second;
			}
		}
		else {
			res.first++;
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<string> a(n);
	arrput(a);

	vector<vector<bool>> v(n, vector<bool>(m, false));
	pair<int, int> res = {0, 0};
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (!v[i][j] and a[i][j] == '.') {
				res = max(res, dfs(i, j, a, v));
			}
		}
	}
	print(res.first, res.second);
}

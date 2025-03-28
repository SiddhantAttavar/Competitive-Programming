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

void dfs(int x, int y, vector<pair<int, int>> &res, vector<vector<bool>> &v) {
	res.push_back({x, y});
	v[x][y] = true;
	if (x > 0 and !v[x - 1][y]) {
		dfs(x - 1, y, res, v);
	}
	if (x < v.size() - 1 and !v[x + 1][y]) {
		dfs(x + 1, y, res, v);
	}
	if (y > 0 and !v[x][y - 1]) {
		dfs(x, y - 1, res, v);
	}
	if (y < v[0].size() - 1 and !v[x][y + 1]) {
		dfs(x, y + 1, res, v);
	}
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<string> s(n);
	arrput(s);

	vector<vector<bool>> v(n, vector<bool>(m, false));
	rep(i, 0, n) {
		rep(j, 0, m) {
			v[i][j] = s[i][j] == '#';
		}
	}

	vector<pair<int, int>> res;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (!v[i][j]) {
				dfs(i, j, res, v);
			}
		}
	}

	rep(i, res.size() - k, res.size()) {
		s[res[i].first][res[i].second] = 'X';
	}
	rep(i, 0, n) {
		print(s[i]);
	}
}

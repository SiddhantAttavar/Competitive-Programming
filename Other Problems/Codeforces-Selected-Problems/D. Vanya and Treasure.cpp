#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int k = 500;

	int n, m, p;
	input(n, m, p);

	vector<vector<int>> a(n, vector<int>(m));
	rep(i, 0, n) {
		arrput(a[i]);
	}

	vector<vector<pair<int, int>>> v(p);
	rep(i, 0, n) {
		rep(j, 0, m) {
			a[i][j]--;
			v[a[i][j]].push_back({i, j});
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, 1e18));
	for (auto [i, j] : v[0]) {
		dp[i][j] = i + j;
	}

	rep(x, 1, p) {
		if ((int) min(v[x].size(), v[x - 1].size()) <= k) {
			for (auto [i, j] : v[x]) {
				for (auto [a, b] : v[x - 1]) {
					dp[i][j] = min(dp[i][j], dp[a][b] + abs(a - i) + abs(b - j));
				}
			}
			continue;
		}

		int z = 1e18;
		for (auto [i, j] : v[x - 1]) {
			z = min(z, dp[i][j]);
		}
		vector<vector<pair<int, int>>> w(600);
		vector<vector<int>> d(n, vector<int>(m, 1e18));
		for (auto [i, j] : v[x - 1]) {
			if (dp[i][j] < z + 600) {
				w[dp[i][j] - z].push_back({i, j});
				d[i][j] = dp[i][j];
			}
		}
		rep(y, 1, 600) {
			for (auto [i, j] : w[y - 1]) {
				vector<pair<int, int>> l = {
					{i - 1, j},
					{i + 1, j},
					{i, j - 1},
					{i, j + 1}
				};
				for (auto [u, v] : l) {
					if (min(u, v) >= 0 and u < n and v < m and d[u][v] > d[i][j] + 1) {
						d[u][v] = d[i][j] + 1;
						w[y].push_back({u, v});
					}
				}
			}
		}
		for (auto [i, j] : v[x]) {
			dp[i][j] = d[i][j];
		}
	}

	print(dp[v[p - 1][0].first][v[p - 1][0].second]);
}

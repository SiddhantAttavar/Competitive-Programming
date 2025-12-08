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
const int MOD = 998244353;

int dfs(int u, int p1, int p2, vector<vector<int>> &graph, vector<int> &s, vector<int> &pow2) {
	int res = 0, n = graph.size();
	for (int v : graph[u]) {
		if (v != p1 and v != p2) {
			res = (res + dfs(v, u, -1, graph, s, pow2)) % MOD;
			res = (res + 2 * (pow2[n] - pow2[n - s[v]] + MOD)) % MOD;
			s[u] += s[v];
		}
	}
	return res;
}

int32_t main() {
	const int N = 1e4;
	vector<int> pow2(N + 1);
	pow2[0] = 1;
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n, -1);
		vector<vector<int>> graph(n);
		rep(i, 1, n) {
			input(p[i]);
			p[i]--;
			graph[i].push_back(p[i]);
			graph[p[i]].push_back(i);
		}

		vector<int> v;
		int u = n - 1;
		while (u) {
			v.push_back(u);
			u = p[u];
		}
		v.push_back(0);

		int k = v.size();
		vector<int> s(n, 1);
		int res = dfs(v[0], v[1], -1, graph, s, pow2);
		rep(i, 1, k - 1) {
			res = (res + dfs(v[i], v[i - 1], v[i + 1], graph, s, pow2)) % MOD;
		}
		res = (res + dfs(v[k - 1], v[k - 2], -1, graph, s, pow2)) % MOD;

		vector<vector<int>> dp(k, vector<int>(k, 0)), pdp(k, vector<int>(k + 1, 0)), qdp(k + 1, vector<int>(k, 0));
		dp[0][0] = pow2[s[v[0]]];
		rep(j, 0, k) {
			pdp[0][j + 1] = (pdp[0][j] + dp[0][j]) % MOD;
			qdp[1][j] = (qdp[0][j] + dp[0][j]) % MOD;
		}
		rep(i, 1, k) {
			int z = (pow2[s[v[i]]] + MOD - (i < k - 1)) % MOD;
			rep(j, 0, i) {
				dp[i][i - j] = z * (pdp[j][i - j] + qdp[i][i - j] - qdp[j][i - j] + MOD) % MOD;
			}
			rep(j, 0, k) {
				pdp[i][j + 1] = (pdp[i][j] + dp[i][j]) % MOD;
				qdp[i + 1][j] = (qdp[i][j] + dp[i][j]) % MOD;
			}
		}

		rep(i, 0, k) {
			res = (res + dp[k - 1][i] * 2 * (k - 1 - i)) % MOD;
		}
		print(res);
	}
}

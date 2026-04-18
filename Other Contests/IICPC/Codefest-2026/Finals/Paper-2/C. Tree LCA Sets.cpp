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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

void dfs(int u, vector<vi> &graph, vi &dp1, vi &dp2, vi &s) {
	for (int v : graph[u]) {
		dfs(v, graph, dp1, dp2, s);
		s[u] += s[v];
	}

	// Take root
	dp1[u] = 1;
	dp2[u] = (u + 1) * s[u] % MOD;

	for (int v : graph[u]) {
		// Only take from this subtree
		dp1[u] = (dp1[u] + dp1[v]) % MOD;
		dp2[u] = (dp2[u] + dp2[v] + (s[u] - s[v]) * (u + 1) % MOD * dp1[v]) % MOD;
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi p(n - 1);
		arrput(p);
		p.insert(p.begin(), 0);
		rep(i, 0, n) {
			p[i]--;
		}

		vector<vi> graph(n);
		rep(i, 1, n) {
			graph[p[i]].push_back(i);
		}

		vi s(n, 1), dp1(n), dp2(n);
		dfs(0, graph, dp1, dp2, s);
		print(dp2[0]);
	}
}

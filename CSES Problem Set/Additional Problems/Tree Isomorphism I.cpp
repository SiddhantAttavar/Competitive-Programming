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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int dfs(int u, int p, vector<vi> &graph, vi &s, vi &pow2) {
	vector<pii> l;
	for (int v : graph[u]) {
		if (v != p) {
			l.push_back({dfs(v, u, graph, s, pow2), v});
			s[u] += s[v];
		}
	}
	sort(all(l));
	int res = 0;
	for (auto [x, v] : l) {
		res = (res * pow2[2 * s[v]] + x) % MOD;
	}
	res = (res * 2 + 1) % MOD;
	return res;
}

int32_t main() {
	const int N = 2e5;
	vi pow2(N + 1, 1);
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vi> g1(n), g2(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			g1[u - 1].push_back(v - 1);
			g1[v - 1].push_back(u - 1);
		}
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			g2[u - 1].push_back(v - 1);
			g2[v - 1].push_back(u - 1);
		}

		vi s1(n, 1), s2(n, 1);
		if (dfs(0, -1, g1, s1, pow2) == dfs(0, -1, g2, s2, pow2)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}

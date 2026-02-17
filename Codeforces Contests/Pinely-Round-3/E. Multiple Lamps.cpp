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

const int N = 20;

void dfs(int u, vector<vi> &graph, int &c) {
	c |= 1 << u;
	for (int v : graph[u]) {
		if (!(c >> v & 1)) {
			dfs(v, graph, c);
		}
	}
}

int32_t main() {
	vector<vi> dp(N);
	rep(n, 1, N) {
		rep(i, 1, 1 << n) {
			int b = 0;
			rep(j, 0, n) {
				if (!(i >> j & 1)) {
					continue;
				}
				for (int k = j + 1; k <= n; k += j + 1) {
					b ^= 1 << k;
				}
			}
			if (__builtin_popcountll(b) <= n / 5) {
				dp[n].push_back(i);
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
		}

		if (n >= N) {
			print(n);
			rep(i, 0, n) {
				cout << i + 1 << ' ';
			}
			cout << endl;
			continue;
		}

		if (n < 5) {
			print(-1);
			continue;
		}

		vi v(n, 0);
		rep(i, 0, n) {
			dfs(i, graph, v[i]);
		}

		int res = -1;
		for (int i : dp[n]) {
			int x = 0;
			rep(j, 0, n) {
				if (i >> j & 1) {
					x |= v[j];
				}
			}
			if (x == i) {
				res = i;
				break;
			}
		}

		if (res == -1) {
			print(res);
			continue;
		}
 
		vi l;
		rep(i, 0, n) {
			if (res >> i & 1) {
				l.push_back(i + 1);
			}
		}
		print(sz(l));
		arrprint(l);
	}
}

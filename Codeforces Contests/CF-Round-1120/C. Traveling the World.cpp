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
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

void dfs(int u, vector<vi> &graph, vi &vis) {
	for (int v : graph[u]) {
		if (vis[v] == -1) {
			vis[v] = 1 - vis[u];
			dfs(v, graph, vis);
		}
	}
}

int brute(vi a) {
	int res = 0;
	do {
		vi s = a;
		for (int i = sz(a) - 2; i >= 0; i--) {
			s[i] = max(s[i + 1], s[i]);
		}
		vi p(sz(a));
		iota(all(p), 0);
		bool flag = false;
		do {
			flag = true;
			rep(i, 0, sz(p) - 1) {
				if (a[p[i]] + a[p[i + 1]] != s[p[i]]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				break;
			}
		} while (next_permutation(all(p)));
		if (flag) {
			arrprint(a);
			res++;
		}
	} while (next_permutation(all(a)));
	return res;
}

int get(vi a, int z) {
	int n = sz(a);
	vi fact(n + 1, 1);
	rep(i, 2, n + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	map<int, int> m;
	rep(i, 0, n) {
		m[a[i]] = i;
	}

	vector<vi> graph(n);
	rep(i, 0, n) {
		if (m.count(a[n - 1] - a[i])) {
			int j = m[a[n - 1] - a[i]];
			graph[i].push_back(j);
		}
	}
	rep(i, 0, n) {
		if (m.count(z - a[i])) {
			int j = m[z - a[i]];
			graph[i].push_back(j);
		}
	}

	vi vis(n, -1);
	vis[n - 1] = 0;
	dfs(n - 1, graph, vis);
	if (count(all(vis), -1)) {
		return 0;
	}

	int x = count(all(vis), 0);
	return fact[x - 2] * fact[n - x] % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);


		vi a(n);
		arrput(a);

		int res = (get(a, a[n - 2]) + get(a, a[n - 3])) % MOD;
		print(res);
	}
}

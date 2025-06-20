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

const int N = 2e5;

int32_t main() {
	setup();

	vector<int> spf(N + 1);
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	int  n;
	input(n);

	vector<int> p(n);
	arrput(p);

	vector<bool> vis(n, false);
	map<int, int> m;
	rep(i, 0, n) {
		if (vis[i]) {
			continue;
		}

		int u = i, c = 0;
		while (!vis[u]) {
			c++;
			vis[u] = true;
			u = p[u] - 1;
		}

		map<int, int> s;
		while (c != 1) {
			s[spf[c]]++;
			c /= spf[c];
		}
		for (auto [k, v] : s) {
			m[k] = max(m[k], v);
		}
	}

	int res = 1;
	for (auto [k, v] : m) {
		rep(i, 0, v) {
			res = res * k % MOD;
		}
	}
	print(res);
}

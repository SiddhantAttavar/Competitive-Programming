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
const int MOD = 998244353;

vector<int> factor(int x, vector<int> &spf) {
	set<int> s;
	while (x > 1) {
		s.insert(spf[x]);
		x /= spf[x];
	}
	vector<int> l {1};
	for (int p : s) {
		vector<int> nl = l;
		for (int j : l) {
			nl.push_back(p * j);
		}
		l = nl;
	}
	l.erase(l.begin());
	return l;
}

int32_t main() {
	setup();
	int n;
	input(n);

	int N = 1e6;
	vector<int> spf(N + 1), f(N + 1, 0);
	iota(spf.begin(), spf.end(), 0);
	rep(i, 2ll, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
			f[j]++;
		}
	}

	vector<int> a(n);
	arrput(a);

	vector<int> dp(N + 1, 0);
	int x = 1;
	for (int i : factor(a[0], spf)) {
		dp[i] = x;
	}
	// arrprint(f);
	// arrprint(dp);
	rep(i, 1, n) {
		int c = 0;
		vector<int> v = factor(a[i], spf);
		for (int j : v) {
			// print(a[i], j);
			if (f[j] % 2) {
				c = (c + dp[j]) % MOD;
			}
			else {
				c = (c - dp[j] + MOD) % MOD;
			}
		}
		for (int j : v) {
			dp[j] = (dp[j] + c) % MOD;
		}
		x = c;
		// print(i, a[i], c);
		// arrprint(dp);
	}
	print(x);
}

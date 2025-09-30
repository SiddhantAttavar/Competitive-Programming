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

int32_t main() {
	setup();

	int n;
	input(n);
	
	if (n == 1) {
		print(1);
		return 0;
	}

	vector<int> a(n);
	arrput(a);
	rep(i, 0, n) {
		if (a[i] != -1) {
			a[i]--;
		}
	}

	// f: left, g: right, h: other
	vector<int> f(n, 0), g(n, 0), h(n, 0);
	f[0] = 0;
	if (a[0] == -1) {
		g[0] = 1;
		h[0] = n - 1;
	}
	else if (a[0] == 1) {
		g[0] = 1;
	}
	else {
		h[0] = 1;
	}
	rep(i, 1, n) {
		if (a[i] == i - 1) {
			f[i] = (f[i - 1] + g[i - 1] + h[i - 1]) % MOD;
		}
		else if (a[i] == i + 1) {
			g[i] = g[i - 1];
		}
		else if (a[i] != -1) {
			h[i] = g[i - 1];
		}
		else {
			f[i] = (f[i - 1] + g[i - 1] + h[i - 1]) % MOD;
			g[i] = g[i - 1];
			h[i] = g[i - 1] * (n - 2 + (i == n - 1)) % MOD;
		}
	}
	print((f[n - 1] + h[n - 1]) % MOD);
}

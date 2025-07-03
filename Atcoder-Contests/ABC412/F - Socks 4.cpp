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

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

int32_t main() {
	setup();

	int n, c;
	input(n, c);

	vector<int> a(n);
	arrput(a);
	c--;
	a[c]++;
	int y = a[c];
	sort(a.begin(), a.end());

	int u = find(a.begin(), a.end(), y) - a.begin();
	vector<int> p(n + 1, 0);
	p[0] = 0;
	rep(i, 0, n) {
		p[i + 1] = (p[i] + a[i]) % MOD;
	}

	int x = 0, k = accumulate(a.begin(), a.end(), 0ll) % MOD, z = 0;
	for (int i = n - 1; i >= u; i--) {
		z = mod_div(
			(a[i] - 1 + p[i] + x + MOD) % MOD,
			(k - 1 - p[i] + 2 * MOD) % MOD
		);
		x = (x + (z + 1) * a[i]) % MOD;
	}
	print(z);
}

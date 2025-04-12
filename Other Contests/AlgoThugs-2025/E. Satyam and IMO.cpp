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
	int N = 1e6;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	setup();
	int n, k;
	input(n, k);

	vector<pair<int, bool>> v(2 * n);
	rep(i, 0, n) {
		int l, r;
		input(l, r);
		v[2 * i] = {l, true};
		v[2 * i + 1] = {r + 1, false};
	}
	sort(v.begin(), v.end());

	int s = 0, res = 0;
	rep(i, 0, 2 * n - 1) {
		s += v[i].second - !v[i].second;
		res = (res + (v[i + 1].first - v[i].first) * (mod_div(fact[n], fact[n - k] * fact[k] % MOD) - (n - s >= k ? mod_div(fact[n - s], fact[n - s - k] * fact[k] % MOD) : 0) + MOD)) % MOD;
	}
	print(res);
}

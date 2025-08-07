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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
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
	int N = 1e5;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		int x = 0;
		for (int i : a) {
			x += i >= k;
		}

		vector<int> p(n + 1);
		p[0] = 1;
		p[1] = x == n ? 0 : n - x;
		rep(i, 2, n - x + 1) {
			p[i] = (p[i - 2] + mod_div(fact[n - x], fact[i] * fact[n - x - i] % MOD)) % MOD;
		}
		rep(i, max(2ll, n - x + 1), n + 1) {
			p[i] = p[i - 2];
		}

		int res = 0;
		rep(i, 1, x + 1) {
			res = (res + p[i - 1] * mod_div(fact[x], fact[i] * fact[x - i] % MOD)) % MOD;
		}
		print(res);
	}
}

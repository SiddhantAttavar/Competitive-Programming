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
	setup();

	int n, m;
	input(n, m);

	string s;
	input(s);

	vector<int> f(26, 0);
	for (char c : s) {
		f[c - 'a']++;
	}

	vector<int> fact(m + 1, 1), inv_fact(m + 1, 1);
	rep(i, 2, m + 1) {
		fact[i] = fact[i - 1] * i % MOD;
		inv_fact[i] = mod_div(inv_fact[i - 1], i);
	}

	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	rep(i, 0, 26) {
		vector<int> ndp(m + 1, 0);
		rep(j, 0, m + 1) {
			rep(k, 0, min(m - j, f[i]) + 1) {
				ndp[j + k] = (ndp[j + k] + dp[j] * inv_fact[k]) % MOD;
			}
		}
		dp = ndp;
	}
	print(dp[m] * fact[m] % MOD);
}

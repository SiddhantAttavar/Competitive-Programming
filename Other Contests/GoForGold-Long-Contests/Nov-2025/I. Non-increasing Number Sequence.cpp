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
	const int N = 2e5;
	vector<int> spf(N + 1);
	vector<int> fact(N + 1, 1);
	iota(spf.begin(), spf.end(), 0);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
		if (spf[i] != i) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	vector<vector<int>> dp(N + 1, vector<int>(20, 0));
	dp[1][1] = 1;
	vector<map<int, int>> f(N + 1);
	rep(i, 2, N + 1) {
		f[i] = f[i / spf[i]];
		f[i][spf[i]]++;
		vector<int> l = {1};
		for (auto [k, v] : f[i]) {
			vector<int> nl = l;
			int z = 1;
			rep(u, 0, v) {
				z *= k;
				for (int j : l) {
					nl.push_back(j * z);
				}
			}
			l = nl;
		}
		l.pop_back();
		for (int j : l) {
			rep(k, 0, 19) {
				dp[i][k + 1] = (dp[i][k + 1] + dp[j][k]) % MOD;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int x, m;
		input(x, m);

		int res = 0;
		rep(k, 1, min(m + 1, 20ll)) {
			res = (res + dp[x][k] * mod_div(fact[m - 1], fact[k - 1] * fact[m - k] % MOD)) % MOD;
		}
		print(res);
	}
}

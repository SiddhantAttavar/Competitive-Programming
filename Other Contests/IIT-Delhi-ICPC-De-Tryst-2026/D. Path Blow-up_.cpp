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

int32_t main() {
	setup();
	const int N = 300;
	vector<vi> comb(N + 1, vi(N + 1, 0));
	rep(i, 0, N + 1) {
		comb[i][0] = 1;
		comb[i][i] = 1;
		rep(j, 1, i) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}

	int n, s;
	input(n, s);

	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);
	}

	map<__int128_t, int> dp = {{s, 1}};
	for (int i = 60; i >= 0; i--) {
		map<__int128_t, int> ndp = dp;
		rep(j, 1, n) {
			__int128_t x = ((__int128_t) j * (n - j)) << i;
			for (auto [k, v] : dp) {
				ndp[k - x] = (ndp[k - x] + v * comb[n - 1][j]) % MOD;
			}
		}
		__int128_t z = ((__int128_t) comb[n - 1][(n - 1) / 2]) * ((1ll << i) - 1);
		dp.clear();
		for (auto [k, v] : ndp) {
			if (k >= 0 and k <= z) {
				dp[k] = v;
			}
		}
	}
	print(dp[0]);
}

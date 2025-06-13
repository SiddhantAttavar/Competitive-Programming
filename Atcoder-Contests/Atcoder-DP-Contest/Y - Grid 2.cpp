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

	int h, w, n;
	input(h, w, n);

	vector<int> fact(N + 1);
	fact[0] = 1;
	rep(i, 1, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	vector<pair<int, int>> v(n);
	rep(i, 0, n) {
		input(v[i].first, v[i].second);
	}
	v.push_back({h, w});

	sort(v.begin(), v.end());
	map<pair<int, int>, int> dp;
	for (auto [x, y] : v) {
		dp[{x, y}] = mod_div(fact[x + y - 2], fact[x - 1] * fact[y - 1] % MOD);
		for (auto [a, b] : v) {
			if (a <= x and b <= y and (a != x or b != y)) {
				dp[{x, y}] = (
					dp[{x, y}] + MOD - 
					mod_div(
						dp[{a, b}] * fact[x - a + y - b] % MOD,
						fact[x - a] * fact[y - b] % MOD
					)
				) % MOD;
			}
		}
	}
	print(dp[{h, w}]);
}

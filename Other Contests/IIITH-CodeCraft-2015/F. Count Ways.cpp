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
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<pair<int, int>> v(k);
		rep(i, 0, k) {
			input(v[i].first, v[i].second);
		}
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.first + a.second < b.first + b.second;
		});
		if (!v.empty() and v.back() == make_pair(n, m)) {
			print(0);
			continue;
		}
		v.push_back({n, m});

		map<pair<int, int>, int> dp;
		for (auto [x, y] : v) {
			dp[{x, y}] = mod_div(fact[x + y - 2], fact[x - 1] * fact[y - 1] % MOD);
			for (auto [i, j] : v) {
				if (i <= x and j <= y and (i < x or j < y)) {
					dp[{x, y}] = (dp[{x, y}] - dp[{i, j}] * mod_div(fact[x - i + y - j], fact[x - i] * fact[y - j] % MOD) % MOD + MOD) % MOD;
				}
			}
		}
		print(dp[{n, m}]);
	}
}

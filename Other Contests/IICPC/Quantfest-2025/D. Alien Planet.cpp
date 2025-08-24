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
	return a * mod_div(b, MOD - 2) % MOD;
}

int solve(int x, int i, int d, int k) {
	if (x == k) {
		print(i);
		return 1;
	}
	if (x <= 0 or i > d) {
		return 0;
	}
	return solve(x, i + 1, d, k) + solve(x + (1 << i), i + 1, d, k) + solve(x - (1 << (i - 1)), i + 1, d, k);
}

int32_t main() {
	// print(solve(1, 1, 10, 277));
	// int f13 = mod_div(1, 3), f29 = mod_div(2, 9);
	int M = 1;
	rep(i, 0, 30) {
		M *= 3;
	}
	setup(); int tc; input(tc); while (tc--) {
		int k;
		input(k);

		if (k == 1) {
			print(1);
			continue;
		}

		vector<int> x(64 - __builtin_clzll(k));
		x[0] = 1;
		x[1] = 1;
		rep(i, 2ll, x.size()) {
			if ((k & (1 << i)) or (k & (1 << (i - 1)))) {
				x[i] = x[i - 1];
			}
			else {
				x[i] = x[i - 2] + x[i - 1];
			}
		}
		int y = x.back(), z = x.size() - 1;
		while (y % 3 == 0) {
			y /= 3;
			z--;
		}
		print((y + z) % MOD);
	}
}

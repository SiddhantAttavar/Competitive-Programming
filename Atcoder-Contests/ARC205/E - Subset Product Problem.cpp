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

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	vector<int> v(1 << 20, 1), w(1 << 20, 1);
	bool flag = false;
	for (int i : a) {
		if (i == 0) {
			flag = true;
		}
		if (flag) {
			print(0);
			continue;
		}

		v[i] = v[i] * i % MOD;
		int res = v[i];
		if (__builtin_popcount(i) <= 10) {
			for (int j = i; j; ) {
				--j &= i;
				res = res * v[j] % MOD;
			}
			print(res);
		}
		else {
			int x = ((1 << 20) - 1) ^ i;
			for (int j = x; j; ) {
				if (__builtin_popcount(j) & 1) {
					res = res * w[j] % MOD;
				}
				else {
					res = mod_div(res, w[j]);
				}
				res = res * v[i | j] % MOD;
				--j &= x;
			}
			print(res);
		}
	}
}

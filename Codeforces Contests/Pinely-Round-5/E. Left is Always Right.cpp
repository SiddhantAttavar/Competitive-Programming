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

int N = 1e6;
vector<int> fact(N + 1, 1);

int modDiv(int a, int b) {
	int x = MOD - 2;
	int res = 1;
	while (x) {
		if (x & 1) {
			res = (res * b) % MOD;
		}

		b = (b * b) % MOD;
		x >>= 1;
	}
	return (a * res) % MOD;
}

int comb(int n, int r) {
	return modDiv(fact[n], fact[r] * fact[n - r] % MOD);
}

int get(int l, int x, int y) {
	int z = l - x - y;
	int res = 0;
	rep(a, 0, z + 1) {
		if (y + a >= x + (z - a)) {
			res = (res + comb(z, a)) % MOD;
		}
	}
	return res;
}

int32_t main() {
	rep(i, 2, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		string s;
		input(s);

		int res = 0;
		string t = s.substr(0, n - k + 1);
		int x = 0, y = 0;;
		rep(i, n - k + 1, n) {
			x += s[i] == '0';
			y += s[i] == '1';
		}
		if (t.find('0') == string::npos) {
			res = (res + get(k - 1, x, y)) % MOD;
		}
		if (t.find('1') == string::npos) {
			res = (res + get(k - 1, y, x)) % MOD;
		}

		vector<int> v(k - 1, 0);
		bool flag = true;
		rep(i, 0, n) {
			if (s[i] == '0') {
				if (v[i % (k - 1)] == 1) {
					flag = false;
					break;
				}
				v[i % (k - 1)] = -1;
			}
			else if (s[i] == '1') {
				if (v[i % (k - 1)] == -1) {
					flag = false;
					break;
				}
				v[i % (k - 1)] = 1;
			}
		}

		if (!flag or k == n) {
			print(res);
			continue;
		}

		bool p = false, q = false;
		rep(i, 1, n - k + 1) {
			if (v[i % (k - 1)] == -1) {
				p = true;
			}
			else if (v[i % (k - 1)] == 1) {
				q = true;
			}
		}

		int c = 1;
		rep(i, 0, k - 1) {
			if (v[i] == 0) {
				c = c * 2 % MOD;
			}
		}
		if (!p or !q) {
			c = (c + MOD - 1) % MOD;
		}

		res = (res + c) % MOD;
		print(res);
	}
}

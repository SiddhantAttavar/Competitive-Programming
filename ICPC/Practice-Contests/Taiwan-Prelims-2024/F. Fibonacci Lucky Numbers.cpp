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

const int K = 1e10, PHI_1 = 15e10, PHI_2 = 4e18, PHI_3 = 16e8;
array<__int128_t, 4> matmul(array<__int128_t, 4> a, array<__int128_t, 4> b) {
	return {
		(a[0] * b[0] + a[1] * b[2]) % K,
		(a[0] * b[1] + a[1] * b[3]) % K,
		(a[2] * b[0] + a[3] * b[2]) % K,
		(a[2] * b[1] + a[3] * b[3]) % K
	};
}

array<__int128_t, 4> matpow(array<__int128_t, 4> a, int b) {
	array<__int128_t, 4> res = {1, 0, 0, 1};
	while (b) {
		if (b & 1) {
			res = matmul(res, a);
		}
		a = matmul(a, a);
		b >>= 1;
	}
	return res;
}

int mod_pow(__int128_t a, int b, int m) {
	__int128_t res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int fib(int n) {
	return matpow({0, 1, 1, 1}, n + 1)[0];
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		n = PHI_3 + mod_pow(7, n, PHI_3);
		n = PHI_2 + mod_pow(7, n, PHI_2);
		n = PHI_1 + mod_pow(7, n, PHI_1);

		string s = to_string(fib(n));
		reverse(s.begin(), s.end());
		while (s.size() < 10) {
			s += '0';
		}
		reverse(s.begin(), s.end());
		print(s);
	}
}

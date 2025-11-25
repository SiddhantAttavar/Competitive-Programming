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

int mod_pow(int a, int b, int m = MOD) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % m;
		}
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

#define ll long long

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

int mod_inv(int a, int b = MOD) {
	int x, y;
	euclid(a, b, x, y);
	return (x % b + b) % b;
}

int gcd(int a, int b) {
	int x, y;
	return euclid(a, b, x, y);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, c;
		input(n, k, c);

		if (n < k) {
			print(-1);
			continue;
		}

		int q = mod_pow(2, n - n % k, c);
		int r = mod_pow(2, n % k);

		int g = gcd(q, c);
		int x = c - g;

		int nc = c / g;
		int nx = x / g;
		int nq = q / g;

		print(x * r % MOD, nx * mod_inv(nq, nc) % nc);
	}
}

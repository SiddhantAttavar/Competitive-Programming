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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

int mpow(int a, int b) {
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

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

const int N = 2e6;
vi pow2(N + 1), fact(N + 1), inv_fact(N + 1);

int comb(int n, int r) {
	if (n < r or r < 0 or n < 0) {
		return 0;
	}
	return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int get(int n, int k) {
	return comb(n + k - 1, k - 1);
}

int32_t main() {
	fact[0] = 1;
	pow2[0] = 1;
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int res = 0;
		rep(k, 0ll, n / 2 + 1) {
			int z = (n - 2 * k) * (n - 2 * k + 1) / 2;
			z += (n - 2 * k) * k;
			z += k * (k + 1);
			z %= MOD;

			res = (res + z * pow2[k] % MOD * get(n - 2 * k, k)) % MOD;
			res = (res + z * pow2[k + 1] % MOD * get(n - 2 * k - 1, k + 1)) % MOD;
		}
		print(res);
	}
}

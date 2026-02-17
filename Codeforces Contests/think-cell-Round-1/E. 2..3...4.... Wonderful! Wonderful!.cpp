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
const int MOD = 998244353;

const int N = 1e6;
vi fact(N + 1, 1), inv_fact(N + 1, 1);

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

int comb(int n, int r) {
	if (n < r or r < 0) {
		return 0;
	}
	return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int32_t main() {
	rep(i, 1, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]) % MOD;
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		rep(k, 1, (n - 1) / 2 + 1) {
			int res = 1;
			for (int x = 1; 2 * k * x < n; x++) {
				int z = (comb(n, 2 * k * x) - comb(n - 2 * k * x + 2 * k - 1, 2 * k - 1) + MOD) % MOD;
				// int z = (comb(n, 2 * k * x) - comb(n - x, 2 * k * x - x)) % MOD;
				res = (res + z) % MOD;
			}
			cout << res << ' ';
		}
		cout << endl;
	}
}

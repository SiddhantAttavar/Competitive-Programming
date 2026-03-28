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
const int MOD = (int) 1e9 + 7; //998244353;

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

int32_t main() {
	const int N = 1e5;
	vi pow2(N + 1, 1), fact(N + 1, 1), inv_fact(N + 1);
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mpow(fact[N], MOD - 2);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi b(n);
		arrput(b);
		b.insert(b.begin(), 0);

		vi x(29, 0);
		for (int i = n; i > 0; i--) {
			if (b[i] == 0) {
				continue;
			}

			rep(j, 0, 29) {
				if (!(b[i] >> j & 1)) {
					continue;
				}
				x[j] = i;
				for (int k = i - 1; k >= 0; k--) {
					int z = fact[i] * inv_fact[k] % MOD * inv_fact[i - k] % MOD;
					b[k] = (b[k] - (z << j) % MOD + MOD) % MOD;
				}
			}
		}

		vi res(n, 0);
		rep(j, 0, 29) {
			rep(i, 0, x[j]) {
				res[i] |= 1ll << j;
			}
		}
		arrprint(res);
	}
}

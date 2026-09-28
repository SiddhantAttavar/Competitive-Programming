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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

const int N = 2e5;
vi fact(N + 1, 1), inv_fact(N + 1, 1);

int comb(int n, int r) {
	return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int32_t main() {
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i > 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi p(n);
		arrput(p);

		ordered_set o;
		vi c(n);
		rep(i, 0, n) {
			c[i] = o.size() - o.order_of_key(p[i]);
			o.insert(p[i]);
		}

		o.clear();
		rep(i, 0, n) {
			if (c[i]) {
				o.insert(i);
			}
		}

		map<int, int, greater<int>> m;
		rep(i, 0, n) {
			if (c[i]) {
				m[c[i]]++;
			}
		}

		int res = 1, z = 0;
		for (auto [k, v] : m) {
			int t = o.size() - o.order_of_key(k) - z;
			res = res * comb(t, v) % MOD;
			z += v;
		}
		print(res);
	}
}

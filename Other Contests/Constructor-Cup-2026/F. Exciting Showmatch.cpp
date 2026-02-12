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

int32_t main() {
	const int N = 3e5;
	vi fact(N + 1, 1), pow2(N + 1, 1);
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
		fact[i] = fact[i - 1] * i % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(2 * n);
		arrput(a);

		vi l = {1};
		rep(i, 1, 2 * n) {
			if (a[i] > a[i - 1] + 1) {
				l.push_back(0);
			}
			l.back()++;
		}

		int e = 0, o = 0;
		for (int z : l) {
			e += z % 2 == 0;
			o += z % 2 == 1;
		}
		print(2 * n - sz(l), pow2[e] * mdiv(fact[o], fact[o / 2] * fact[o / 2] % MOD) % MOD);
	}
}

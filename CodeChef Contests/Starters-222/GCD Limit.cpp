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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
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
	const int N = 2e5;
	vector<vi> div(N + 1);
	rep(i, 1, N + 1) {
		for (int j = i; j <= N; j += i) {
			div[j].push_back(i);
		}
	}
	rep(i, 1, N + 1) {
		reverse(all(div[i]));
	}
	setup(); int tc; input(tc); while (tc--) {
		int m;
		input(m);

		vi dp(m + 1, 0), v(m + 1, 0);
		rep(i, 2, m + 1) {
			int x = 0, y = 0;
			for (int j : div[i]) {
				v[j] = m / j;
				for (int k : div[i]) {
					if (k <= j) {
						break;
					}
					if (k % j == 0) {
						v[j] -= v[k];
					}
				}
				if (j < i) {
					x = (x + dp[j] * v[j]) % MOD;
					y = (y + v[j]) % MOD;
				}
			}
			dp[i] = (mdiv(x, y) + 1) % MOD;
		}
		print(mdiv(accumulate(all(dp), 0ll) % MOD, m));
	}
}

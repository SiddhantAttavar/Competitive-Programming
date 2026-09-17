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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vi d(n + 1, 0), c(n, 0), f(n + 1, -1);
		rep(i, 0, n) {
			rep(j, 0, a[i]) {
				int l = (i + 1) * j, r = min(n, (int) (i + 1) * (j + 1));
				c[l]++;
				f[r - 1] = max(f[r - 1], l);
			}
			int l = min(n, (i + 1) * a[i]), r = min(n, (int) (i + 1) * (a[i] + 1));
			d[l]++;
			d[r]--;
		}

		vi v(n + 1, 0);
		rep(i, 0, n) {
			d[i + 1] += d[i];
			v[i + 1] = v[i] + (!d[i]);
			f[i + 1] = max(f[i + 1], f[i]);
		}

		vi p(n + 1, 0), dp(n + 1, 0);
		dp[0] = 1;
		p[0] = dp[0];
		rep(i, 0, n) {
			if (!d[i]) {
				if (!i or f[i - 1] == -1) {
					dp[i + 1] = p[i];
				}
				else {
					dp[i + 1] = (p[i] - p[f[i - 1]] + MOD) % MOD;
				}
			}
			p[i + 1] = (p[i] + dp[i + 1]) % MOD;
		}

		int res = 0;
		rep(i, f[n - 1], n) {
			res = (res + dp[i + 1]) % MOD;
		}
		print(res);
	}
}

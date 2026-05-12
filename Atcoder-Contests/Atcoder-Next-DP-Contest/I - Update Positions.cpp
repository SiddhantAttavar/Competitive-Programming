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

const int N = 1e3;
vector<vi> comb(N + 1, vi(N + 1));

int get(int n, int k) {
	if (n == 0 and k == 0) {
		return 1;
	}
	if (k <= 0 or n < 0) {
		return 0;
	}
	return comb[n + k - 1][k - 1];
}

int32_t main() {
	setup();
	rep(i, 0, N + 1) {
		comb[i][0] = 1;
		comb[i][i] = 1;
		rep(j, 1, i) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}

	int n, l, r;
	input(n, l, r);

	vi a(n);
	arrput(a);

	vi f(n + 1, 0);
	for (int i : a) {
		f[i]++;
	}

	vector<vi> dp(n + 1, vi(n + 1, 0));
	dp[0][0] = 1;
	int x = 0;
	for (int i = n; i > 0; i--) {
		int a = get(f[i], x ? x - 1 : 0), b = get(f[i] - (x ? 1 : 0), x ? x : -1), c = get(f[i] - (x ? 2 : 1), x + 1);
		vector<vi> ndp(n + 1, vi(n + 1, 0));
		rep(u, 0, n + 1) {
			rep(v, 0, n + 1) {
				ndp[u][v] = (ndp[u][v] + dp[u][v] * a) % MOD;
				if (u < n) {
					ndp[u + 1][v] = (ndp[u + 1][v] + dp[u][v] * b) % MOD;
				}
				if (v < n) {
					ndp[u][v + 1] = (ndp[u][v + 1] + dp[u][v] * b) % MOD;
				}
				if (u < n and v < n) {
					ndp[u + 1][v + 1] = (ndp[u + 1][v + 1] + dp[u][v] * c) % MOD;
				}
			}
		}
		dp = ndp;
		x += f[i];
	}
	print(dp[l][r]);
}

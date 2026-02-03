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
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	const int N = 500;
	vector<vi> comb(N + 1, vi(N + 1));
	rep(n, 0, N + 1) {
		comb[n][0] = 1;
		comb[n][n] = 1;
		rep(r, 1, n) {
			comb[n][r] = (comb[n - 1][r] + comb[n - 1][r - 1]) % MOD;
		}
	}

	string s;
	input(s);

	int n = sz(s);

	vector<vi> dp(n, vi(n, 0));
	for (int l = 2; l <= n; l += 2) {
		rep(i, 0, n - l + 1) {
			int j = i + l - 1;
			for (int k = i + 1; k <= j; k += 2) {
				if (s[i] != s[k]) {
					continue;
				}

				int l = k - i + 1, r = j - k;
				int x = k == i + 1 ? 1 : dp[i + 1][k - 1];
				int y = k == j ? 1 : dp[k + 1][j];
				dp[i][j] = (dp[i][j] + x * y % MOD * comb[(l + r) / 2][l / 2]) % MOD;
			}
		}
	}
	print(dp[0][n - 1]);
}

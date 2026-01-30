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
const int MOD = (int) 1e9 + 7; //998244353;

const int N = 2e5;
int dp[10][N + 1][10];
int x[10][N + 1];

int32_t main() {
	rep(i, 0, 10) {
		rep(k, 0, 10) {
			dp[i][0][k] = k == i;
		}
		x[i][0] = accumulate(dp[i][0], dp[i][0] + 10, 0ll) % MOD;
		rep(j, 0, N) {
			dp[i][j + 1][0] = dp[i][j][9];
			dp[i][j + 1][1] = (dp[i][j][0] + dp[i][j][9]) % MOD;
			rep(k, 2, 10) {
				dp[i][j + 1][k] = dp[i][j][k - 1];
			}
			x[i][j + 1] = accumulate(dp[i][j + 1], dp[i][j + 1] + 10, 0ll) % MOD;
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		string s;
		int m;
		input(s, m);

		int res = 0;
		for (char c : s) {
			res = (res + x[c - '0'][m]) % MOD;
		}
		print(res);
	}
}

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> v(n);
	arrput(v);

	int x = 0, y = 0, z = 0;
	for (int i : v) {
		x += i == 1;
		y += i == 2;
		z += i == 3;
	}

	vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, 0)));
	dp[0][0][0] = 0;
	rep(c, 0, n + 1) {
		rep(b, 0, n - c + 1) {
			rep(a, 0, n - c - b + 1) {
				if (a) {
					dp[a][b][c] += a * (dp[a - 1][b][c] + 1);
				}
				if (b) {
					dp[a][b][c] += b * (dp[a + 1][b - 1][c] + 1);
				}
				if (c) {
					dp[a][b][c] += c * (dp[a][b + 1][c - 1] + 1);
				}
				if (a + b + c) {
					dp[a][b][c] += n - (a + b + c);
					dp[a][b][c] /= a + b + c;
				}
			}
		}
	}

	cout << setprecision(15) << fixed;
	print(dp[x][y][z]);
}

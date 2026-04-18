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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		        
		vi a(n);
		arrput(a);

		rep(i, 0, n) {
			a[i]--;
		}

		vector<vi> x(n, vi(n, false));
		rep(i, 0, n) {
			vi f(n, 0);
			int c = 0;
			rep(j, i, n) {
				c -= f[a[j]] == 1;
				f[a[j]]++;
				c += f[a[j]] == 1;
				x[i][j] = c == 0;
			}
		}
		rep(l, 2, n + 1) {
			rep(i, 0, n - l + 1) {
				int j = i + l - 1;
				x[i][j] = x[i][j] or x[i][j - 1] or x[i + 1][j];
			}
		}

		vector<vi> dp(n, vi(n, 1e18));
		rep(l, 1, n + 1) {
			rep(i, 0, n - l + 1) {
				int j = i + l - 1;
				if (!x[i][j]) {
					dp[i][j] = 0;
					continue;
				}
				rep(k, i, j + 1) {
					int p = k == i ? 0 : dp[i][k - 1];
					int q = k == j ? 0 : dp[k + 1][j];
					dp[i][j] = min(dp[i][j], p + q + 1);
				}
			}
		}
		print(dp[0][n - 1]);
	}
}

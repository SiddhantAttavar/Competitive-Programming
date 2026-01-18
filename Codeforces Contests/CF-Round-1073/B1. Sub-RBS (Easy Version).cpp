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

int32_t main() {
	int N = 100;
	vector<vi> comb(N + 1, vi(N + 1, 0));
	rep(i, 0, N + 1) {
		comb[i][0] = 1;
		rep(j, 1, i) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
		comb[i][i] = 1;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		vi p(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i] + (s[i] == '(');
		}

		int res = 0;
		rep(i, 0, n) {
			if (s[i] == '(') {
				continue;
			}

			int x = p[i];
			vi dp(n + 1, 0);
			dp[0] = 1;
			rep(j, i + 1, n) {
				vi ndp = dp;
				if (s[j] == '(') {
					rep(x, 1, n + 1) {
						ndp[x] = (ndp[x] + dp[x - 1]) % MOD;
					}
				}
				else {
					rep(x, 0, n) {
						ndp[x] = (ndp[x] + dp[x + 1]) % MOD;
					}
				}

				if (s[j] == ')') {
					continue;
				}

				int y = (n - j) - (p[n] - p[j]);
			}
		}
		print(res);
	}
}

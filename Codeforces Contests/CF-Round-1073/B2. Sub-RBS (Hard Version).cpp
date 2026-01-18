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

int brute(string &s) {
	int res = 0;
	rep(i, 0, 1 << sz(s)) {
		string t;
		rep(j, 0, sz(s)) {
			if (i >> j & 1) {
				t += s[j];
			}
		}
		int d = 0;
		bool flag = true;
		for (char c : t) {
			if (c == '(') {
				d++;
			}
			else {
				d--;
				if (d < 0) {
					flag = false;
					break;
				}
			}
		}
		if (!flag or d > 0) {
			continue;
		}

		int l = 0;
		while (l < sz(t) and t[l] == '(') {
			l++;
		}
		while (l < sz(t) and t[l] == ')') {
			l++;
		}
		l++;
		while (l < sz(t) and t[l] == ')') {
			l++;
		}
		if (l < sz(t)) {
			res += sz(t) - 2;
		}
	}
	return res;
}

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

		vi p(n + 1);
		rep(i, 0, n) {
			p[i + 1] = p[i] + (s[i] == '(');
		}

		vector<vi> dp(n + 1, vi(n + 1, 0));
		dp[0][0] = 1;
		int res = 0;
		for (int i = n - 1; i >= 0; i--) {
			vector<vi> ndp = dp;
			rep(l, 1, n + 1) {
				if (s[i] == ')') {
					rep(d, 1, n + 1) {
						ndp[l][d] = (ndp[l][d] + dp[l - 1][d - 1]) % MOD;
					}
				}
				else {
					rep(d, 0, n) {
						ndp[l][d] = (ndp[l][d] + dp[l - 1][d + 1]) % MOD;
					}
				}
			}

			if (s[i] == '(') {
				dp = ndp;
				continue;
			}

			rep(x, 1, p[i] + 1) {
				rep(l, 2 * x + 4, n + 1) {
					res = (res + comb[p[i]][x] * (ndp[l - x][x] - dp[l - x][x] + MOD) % MOD * (l - 2)) % MOD;
				}
			}
			dp = ndp;
		}
		print(res);
		// print(brute(s));
	}
}

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
const int MOD = 998244353;

int calc(int d, int c, int x, vector<int> &p) {
	if (c >= d) {
		return (p.back() + x + MOD) % MOD;
	}
	return (p.back() - p[d - c - 1] + x + MOD) % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		int res = 1;
		if (a[0] == -1) {
			res = k;
		}
		if (b.back() == -1) {
			res *= k;
		}
		a.erase(a.begin());
		b.pop_back();
		n--;

		vector<vector<int>> dp(k, vector<int>(k, 0));
		if (a[0] == -1) {
			rep(i, 0, k) {
				if (b[0] != -1) {
					dp[i][b[0] - 1] = 1;
					continue;
				}
				rep(j, 0, k) {
					dp[i][j] = 1;
				}
			}
		}
		else {
			if (b[0] != -1) {
				dp[a[0] - 1][b[0] - 1] = 1;
			}
			else {
				rep(j, 0, k) {
					dp[a[0] - 1][j] = 1;
				}
			}
		}
		int x = 0;
		rep(i, 0, k) {
			rep(j, 0, i + 1) {
				x += dp[i][j];
			}
		}
		vector<int> p(k);
		rep(i, 0, k) {
			rep(j, i + 1, k) {
				p[j - i] += dp[i][j];
			}
		}
		rep(i, 0, k - 1) {
			p[i + 1] += p[i];
		}
		rep(i, 0, k) {
			arrprint(dp[i]);
		}
		cout << endl;

		rep(u, 1, n) {
			vector<vector<int>> ndp(k, vector<int>(k, 0));
			if (a[u] == -1) {
				rep(i, 0, k) {
					if (b[u] != -1) {
						ndp[i][b[u] - 1] = calc(i, b[u] - 1, x, p);
						continue;
					}
					rep(j, 0, k) {
						ndp[i][j] = calc(i, j, x, p);
					}
				}
			}
			else {
				if (b[u] != -1) {
					ndp[a[u] - 1][b[u] - 1] = calc(a[u] - 1, b[u] - 1, x, p);
				}
				else {
					rep(j, 0, k) {
						ndp[a[u] - 1][j] = calc(a[u] - 1, j, x, p);
					}
				}
			}
			int y = 0;
			rep(i, 0, k) {
				rep(j, 0, i + 1) {
					y += ndp[i][j];
					y %= MOD;
				}
			}
			vector<int> np(k);
			rep(i, 0, k) {
				rep(j, i + 1, k) {
					np[j - i] += ndp[i][j];
					np[j - i] %= MOD;
				}
			}
			rep(i, 0, k - 1) {
				np[i + 1] += np[i];
				np[i + 1] %= MOD;
			}
			p = np;
			dp = ndp;
			x = y;

			rep(i, 0, k) {
				arrprint(dp[i]);
			}
			cout << endl;
		}

		print(res * (p.back() + x) % MOD);
	}
}

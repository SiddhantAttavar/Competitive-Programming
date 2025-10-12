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
// #define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

vector<vector<int>> transpose(vector<vector<int>> a) {
	int n = a.size(), m = a[0].size();
	vector<vector<int>> b(m, vector<int>(n));
	rep(i, 0, m) {
		rep(j, 0, n) {
			b[i][j] = a[j][i];
		}
	}
	return b;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> a(n, vector<int>(m));
		rep(i, 0, n) {
			string s;
			input(s);
			rep(j, 0, m) {
				a[i][j] = s[j] == '1';
			}
		}

		bool flag = false;
		if (n >= m) {
			flag = true;
			a = transpose(a);
			swap(n, m);
		}

		vector<vector<int>> dp(n, vector<int>(m, 1e9));
		for (int l = n; l > 0; l--) {
			vector<vector<int>> ndp = dp;
			rep(i, 0, n - l + 1) {
				int j = i + l - 1;
				int x = -1;
				vector<int> v;
				rep(y, 0, m) {
					if (a[i][y] and a[j][y]) {
						v.push_back(y);
					}
				}
				if (i == j) {
					v.clear();
				}
				rep(k, 1, v.size()) {
					int t = (j - i + 1) * (v[k] - v[k - 1] + 1);
					rep(z, v[k - 1], v[k] + 1) {
						ndp[i][z] = min(ndp[i][z], t);
					}
				}

				rep(x, 0, m) {
					if (i > 0) {
						ndp[i][x] = min(ndp[i][x], dp[i - 1][x]);
					}
				}
			}
			dp = ndp;
		}

		vector<vector<int>> res(n, vector<int>(m, 0));
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (dp[i][j] != 1e9) {
					res[i][j] = dp[i][j];
				}
			}
		}

		if (flag) {
			res = transpose(res);
			swap(n, m);
		}

		rep(i, 0, n) {
			arrprint(res[i]);
		}
	}
}

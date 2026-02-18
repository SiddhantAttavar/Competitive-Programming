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
const int MOD = 998244353;

int brute(int n) {
	int res = 0;
	rep(i, 1, 1 << n) {
		vi v;
		rep(j, 0, n) {
			if (i >> j & 1) {
				v.push_back(j);
			}
		}
		if (sz(v) <= 1) {
			continue;
		}
		int c = max(v[1] - v[0], v[sz(v) - 1] - v[sz(v) - 2]);
		rep(j, 1, sz(v) - 1) {
			c = max(c, min(v[j] - v[j - 1], v[j + 1] - v[j]));
		}
		res += c;
	}
	return res;
}

int32_t main() {
	const int N = 2000;
	vector<vector<array<int, 3>>> dp1(N, vector<array<int, 3>>(N, {0, 0, 0}));
	vector<vector<array<int, 3>>> pdp1(N + 1, vector<array<int, 3>>(N, {0, 0, 0}));
	vector<vector<array<int, 3>>> dp2(N, vector<array<int, 3>>(N, {0, 0, 0}));
	vector<vector<array<int, 3>>> pdp2(N + 1, vector<array<int, 3>>(N, {0, 0, 0}));
	rep(i, 0, N) {
		rep(j, 1, N) {
			int k = max(0, i - j + 1);
			dp1[i][j][0] = (
				pdp1[i][j][0] - pdp1[k][j][0] + 
				pdp1[i][j][1] - pdp1[k][j][1] + 
				pdp1[i][j][2] - pdp1[k][j][2] + 
				i - k + 4 * MOD
			) % MOD;
			dp2[i][j][0] = (
				pdp2[i][j][0] - pdp2[k][j][0] + 
				pdp2[i][j][1] - pdp2[k][j][1] + 
				pdp2[i][j][2] - pdp2[k][j][2]
			) % MOD;

			if (i >= j) {
				k = i - j;
				dp1[i][j][1] = dp1[k][j][0];
				dp2[i][j][1] = (dp2[k][j][0] + dp2[k][j][1] + dp2[k][j][2] + dp1[k][j][1] + dp1[k][j][2] + 1) % MOD;

				dp1[i][j][2] = pdp1[k][j][0];
				dp2[i][j][2] = (pdp2[k][j][0] + pdp2[k][j][1] + pdp1[k][j][1]) % MOD;
			}

			pdp1[i + 1][j] = {
				(pdp1[i][j][0] + dp1[i][j][0]) % MOD,
				(pdp1[i][j][1] + dp1[i][j][1]) % MOD,
				(pdp1[i][j][2] + dp1[i][j][2]) % MOD
			};
			pdp2[i + 1][j] = {
				(pdp2[i][j][0] + dp2[i][j][0]) % MOD,
				(pdp2[i][j][1] + dp2[i][j][1]) % MOD,
				(pdp2[i][j][2] + dp2[i][j][2]) % MOD
			};
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int res = 0;
		rep(i, 0, n) {
			rep(j, 0, i + 1) {
				res = (res + (dp1[i][j][1] + dp2[i][j][0] + dp2[i][j][1]) * j) % MOD;
			}
		}
		print(res);
	}
}

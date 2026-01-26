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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, I, V, U;
		input(n, m, I, V, U);

		vi b(n), ir(n), vis(n), area(n);
		rep(i, 0, n) {
			input(b[i], ir[i], vis[i], area[i]);
		}

		vi u(m), au(m);
		rep(i, 0, m) {
			input(u[i], au[i]);
		}

		int A1 = accumulate(all(area), 0), A2 = accumulate(all(au), 0ll);
		vector<vector<vi>> dp1(A1 + 1, vector<vi>(I + 1, vi(V + 1, -1e18)));
		dp1[0][0][0] = 0;
		rep(i, 0, n) {
			vector<vector<vi>> ndp = dp1;
			rep(x, area[i], A1 + 1) {
				rep(y, ir[i], I + 1) {
					rep(z, vis[i], V + 1) {
						ndp[x][y][z] = max(ndp[x][y][z], dp1[x - area[i]][y - ir[i]][z - vis[i]] + b[i]);
					}
				}
			}
			dp1 = ndp;
		}

		vi dp2(A2 + 1, -1e18);
		dp2[0] = 0;
		rep(i, 0, m) {
			vi ndp = dp2;
			rep(x, au[i], A2 + 1) {
				ndp[x] = max(ndp[x], dp2[x - au[i]] + u[i]);
			}
			dp2 = ndp;
		}

		int x = 0;
		while (x <= A2 and dp2[x] < U) {
			x++;
		}
		if (x > A2) {
			print(-1);
			continue;
		}

		int res = -1;
		rep(y, x, A1 + 1) {
			rep(i, 0, I + 1) {
				rep(j, 0, V + 1) {
					res = max(res, dp1[y][i][j]);
				}
			}
		}
		print(res);
	}
}

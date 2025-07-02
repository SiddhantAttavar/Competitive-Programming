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
	setup(); int tc; input(tc); while (tc--) {
		string n;
		input(n);

		int res = 0;
		vector<vector<int>> f(11, vector<int>(11, 0));
		rep(i, 0, n[0] - '0') {
			f[i][0] = 1;
		}
		int x = n[0] - '0', y = 0;
		n.erase(n.begin());
		bool flag = false;
		for (char c : n) {
			vector<vector<int>> g(11, vector<int>(11, 0));
			rep(i, 0, 10) {
				rep(j, 0, 11) {
					rep(k, 0, 11) {
						if (flag) {
							g[(i + j) % 11][k] += f[j][k];
						}
						else {
							g[j][(i + k) % 11] += f[j][k];
						}
					}
				}
			}
			rep(i, 0, c - '0') {
				if (flag) {
					g[(i + x) % 11][y]++;
				}
				else {
					g[x][(i + y) % 11]++;
				}
			}
			if (flag) {
				x = (x + c - '0') % 11;
			}
			else {
				y = (y + c - '0') % 11;
			}
			rep(i, 0, 11) {
				rep(j, 0, 11) {
					f[i][j] = g[i][j] % MOD;
				}
			}
			flag = !flag;
		}
		f[x][y]++;
		print((f[0][0] + MOD - 1) % MOD);
	}
}

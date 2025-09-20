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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<string> a(n);
		arrput(a);

		vector<int> dp(1 << m, 0);
		rep(x, 0, 1 << m) {
			dp[x] = __builtin_popcount(x);
		}
		rep(i, 1, n) {
			vector<int> ndp(1 << m, 1e18);
			rep(x, 0, 1 << m) {
				rep(y, 0, 1 << m) {
					bool flag = true;
					rep(j, 0, m - 1) {
						if ((a[i - 1][j]  == '#' and a[i - 1][j + 1] == '#' and a[i][j] == '#' and a[i][j + 1] == '#') and 
							(!(x >> j & 3) and !(y >> j & 3))) {
							flag = false;
							break;
						}
					}
					if (flag) {
						ndp[x] = min(ndp[x], dp[y] + __builtin_popcount(x));
					}
				}
			}
			dp = ndp;
		}
		print(*min_element(dp.begin(), dp.end()));
	}
}

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
		int n;
		input(n);

		vector<int> a(n), c(n);
		arrput(a);
		arrput(c);

		map<int, int> m;
		for (int i : a) {
			m[i] = 0;
		}

		int x = 0;
		for (auto [k, v] : m) {
			m[k] = x;
			x++;
		}

		rep(i, 0, n) {
			a[i] = m[a[i]];
		}

		vector<int> dp(n, c[0]);
		dp[a[0]] = 0;
		rep(i, 1, n) {
			vector<int> ndp(n);
			int x = 1e18;
			rep(j, 0, n) {
				x = min(x, dp[j]);
				ndp[j] = x + (a[i] == j ? 0 : c[i]);
			}
			dp = ndp;
		}
		print(*min_element(dp.begin(), dp.end()));
	}
}

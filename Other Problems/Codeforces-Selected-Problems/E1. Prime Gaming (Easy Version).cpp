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

		int k;
		input(k);

		vector<int> c(k);
		arrput(c);

		if (m == 1) {
			print(1);
			continue;
		}

		rep(i, 0, k) {
			c[i]--;
		}

		vector<bool> dp = {n % 2 == 0, n % 2 == 1};
		rep(l, 2, n + 1) {
			vector<bool> ndp(1 << l, false);
			rep(x, 0, 1 << l) {
				for (int i : c) {
					if (i >= l) {
						break;
					}
					int y = (x >> (i + 1)) << i | x & ((1 << i) - 1);
					ndp[x] = ndp[x] or !dp[y];
				}
			}
			dp = ndp;
		}

		print((1 << n) + accumulate(dp.begin(), dp.end(), 0ll));
	}
}

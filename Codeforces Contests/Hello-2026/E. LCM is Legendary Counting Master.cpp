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
const int MOD = 998244353;

int32_t main() {
	const int M = 3000;
	vector<vector<int>> v(M + 1);
	rep(i, 1, M + 1) {
		for (int j = i; j <= M; j += i) {
			v[j].push_back(i);
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n);
		arrput(a);

		if (a[0] > 1) {
			print(0);
			continue;
		}

		vector<int> dp(m + 1, 0);
		dp[1] = 1;
		rep(i, 1, n) {
			vector<int> ndp(m + 1, 0);
			rep(x, 1, m + 1) {
				for (int y : v[x]) {
					if (x + y <= m and a[i] == 0 or a[i] == x + y) {
						ndp[x + y] = (ndp[x + y] + dp[x]) % MOD;
					}
				}
			}
			dp = ndp;
		}
		print(accumulate(dp.begin(), dp.end(), 0ll) % MOD);
	}
}

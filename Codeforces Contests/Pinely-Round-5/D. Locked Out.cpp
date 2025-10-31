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

int brute(vector<int> &a) {
	int res = a.size();
	rep(i, 0, 1 << a.size()) {
		vector<bool> v(a.size() + 1, false);
		bool flag = true;
		rep(j, 0, a.size()) {
			if (i >> j & 1) {
				if (v[a[j] - 1]) {
					flag = false;
					break;
				}
				v[a[j]] = true;
			}
		}
		if (flag) {
			res = min(res, (int) a.size() - __builtin_popcount(i));
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> v(n + 1);
		rep(i, 0, n) {
			v[a[i]].push_back(i);
		}

		vector<vector<int>> dp(n + 1);
		dp[0] = {0};
		rep(x, 1, n + 1) {
			dp[x].resize(v[x].size() + 1);
			dp[x].back() = dp[x - 1][0];
			int p = n;
			for (int i = v[x].size() - 1; i >= 0; i--) {
				int k = lower_bound(v[x - 1].begin(), v[x - 1].end(), v[x][i]) - v[x - 1].begin();
				p = min(p, dp[x - 1][k] + k + (int) v[x].size() - i - 1);
				dp[x][i] = min(p, dp[x][i + 1] + 1);
			}
		}
		print(dp[n][0]);
	}
}

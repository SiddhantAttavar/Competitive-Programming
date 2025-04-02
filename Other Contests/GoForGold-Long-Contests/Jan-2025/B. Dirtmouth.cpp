#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	string s;
	input(s);

	vector<vector<int>> a(m, vector<int>(m, 0));
	rep(i, 1, s.size()) {
		a[s[i - 1] - 'a'][s[i] - 'a']++;
		a[s[i] - 'a'][s[i - 1] - 'a']++;
	}

	vector<int> dp(1 << m, 1e18);
	dp[0] = 0;
	rep(i, 1, 1 << m) {
		rep(j, 0, m) {
			if (!((1 << j) & i)) {
				continue;
			}

			int c = 0, x = __builtin_popcount(i);
			rep(k, 0, m) {
				if (j == k) {
					continue;
				}
				if ((1 << k) & i) {
					c += a[j][k] * x;
				}
				else {
					c -= a[j][k] * x;
				}
			}
			dp[i] = min(dp[i], c + dp[i ^ (1 << j)]);
		}
	}
	print(dp[(1 << m) - 1]);
}

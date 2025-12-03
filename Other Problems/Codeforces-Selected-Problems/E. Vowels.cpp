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
	setup();

	int n;
	input(n);

	int k = 24;
	vector<int> dp(1 << k, 0);
	rep(i, 0, n) {
		string s;
		input(s);

		int a = 1 << (s[0] - 'a'), b = 1 << (s[1] - 'a'), c = 1 << (s[2] - 'a');
		dp[a]++;
		dp[b]++;
		dp[c]++;
		dp[a | b]--;
		dp[b | c]--;
		dp[c | a]--;
		dp[a | b | c]++;
	}

	rep(j, 0, k) {
		rep(i, 0, 1 << k) {
			if (i >> j & 1) {
				dp[i] += dp[i ^ (1 << j)];
			}
		}
	}

	int res = 0;
	rep(i, 0, 1 << k) {
		res ^= dp[i] * dp[i];
	}
	print(res);
}

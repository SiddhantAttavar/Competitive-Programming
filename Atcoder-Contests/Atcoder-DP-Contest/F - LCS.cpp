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
	setup();

	string s, t;
	input(s, t);

	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	rep(i, 0, n) {
		rep(j, 0, m) {
			dp[i + 1][j + 1] = max({dp[i + 1][j], dp[i][j + 1], dp[i][j] + (s[i] == t[j])});
		}
	}

	int i = n - 1, j = m - 1;
	string res;
	while (i >= 0 and j >= 0) {
		if (dp[i + 1][j + 1] == dp[i + 1][j]) {
			j--;
		}
		else if (dp[i + 1][j + 1] == dp[i][j + 1]) {
			i--;
		}
		else if (dp[i + 1][j + 1] == dp[i][j] + 1) {
			res += s[i];
			i--;
			j--;
		}
	}

	reverse(res.begin(), res.end());
	print(res);
}

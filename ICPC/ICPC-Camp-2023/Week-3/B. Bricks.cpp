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

	int n, m;
	input(n, m);

	vector<int> a(n + 1);
	rep(i, 0, m) {
		int x;
		input(x);
		a[x]++;
	}

	map<int, int> v;
	v[0] = 0;
	vector<int> dp(n + 1);
	dp[0] = 1;
	int p = 0;
	rep(i, 1, n + 1) {
		if (!a[i]) {
			dp[i] = dp[i - 1];
		}

		p += a[i];

		if (v.count(p - i)) {
			dp[i] = (dp[i] + dp[v[p - i]]) % MOD;
		}
		v[p - i] = i;
	}

	print(dp[n]);
}

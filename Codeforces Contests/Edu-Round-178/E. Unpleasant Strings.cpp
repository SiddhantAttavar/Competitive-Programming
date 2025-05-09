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
	int n, k;
	input(n, k);

	string s;
	input(s);

	vector<int> dp(n + 2, 0);
	dp[n] = 1;
	vector<bool> m(k, false);
	int x = 0, y = 0;
	for (int i = n - 1; i >= 0; i--) {
		m[s[i] - 'a'] = true;
		if (accumulate(m.begin(), m.end(), 0) == k) {
			x++;
			m = vector<bool>(k, false);
		}
		dp[i] = x + (k != accumulate(m.begin(), m.end(), 0));
	}

	vector<vector<int>> v(n, vector<int>(k, n));
	for (int i = n - 2; i >= 0; i--) {
		rep(j, 0, k) {
			v[i][j] = v[i + 1][j];
		}
		v[i][s[i + 1] - 'a'] = i + 1;
	}

	int q;
	input(q);
	while (q--) {
		string t;
		input(t);

		int l = 0;
		int j = s[0] == t[0];
		while (l < n and j < t.size()) {
			l = v[l][t[j] - 'a'];
			j++;
		}

		print(dp[l + 1]);
	}
}

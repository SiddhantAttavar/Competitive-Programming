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

	vector<int> a(n);
	arrput(a);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	a.insert(a.begin(), m);

	vector<vector<int>> b(n + 1);
	rep(i, 0, m) {
		int x, y;
		input(x, y);
		b[x].push_back(y);
	}
	rep(i, 0, n + 1) {
		sort(b[i].begin(), b[i].end());
		reverse(b[i].begin(), b[i].end());
		b[i].insert(b[i].begin(), 0);
		rep(j, 1, b[i].size()) {
			b[i][j] += b[i][j - 1];
		}
	}

	vector<int> dp(m + 1, 0);
	for (int i = n; i >= 0; i--) {
		vector<int> ndp = dp;
		rep(j, 0, b[i].size()) {
			rep(k, j, a[i] + 1) {
				ndp[k] = max(ndp[k], dp[k - j] + b[i][j]);
			}
		}
		dp = ndp;
	}
	print(*max_element(dp.begin(), dp.end()));
}

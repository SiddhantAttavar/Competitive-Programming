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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, ax, ay, bx, by;
		input(n, ax, ay, bx, by);

		vi x(n), y(n);
		arrput(x);
		arrput(y);

		map<int, pii> m;
		rep(i, 0, n) {
			if (!m.count(x[i])) {
				m[x[i]] = {y[i], y[i]};
			}
			else {
				m[x[i]].first = min(m[x[i]].first, y[i]);
				m[x[i]].second = max(m[x[i]].second, y[i]);
			}
		}
		m[ax] = {ay, ay};
		m[bx] = {by, by};

		map<int, pii> dp;
		dp[ax] = {0, 0};
		int z = ax;
		for (auto [x, p] : m) {
			if (x == ax) {
				continue;
			}
			dp[x] = {
				min(abs(p.first - m[z].second) + dp[z].first, abs(p.first - m[z].first) + dp[z].second) + p.second - p.first,
				min(abs(p.second - m[z].second) + dp[z].first, abs(p.second - m[z].first) + dp[z].second) + p.second - p.first
			};
			z = x;
		}
		print(dp[bx].first + bx - ax);
	}
}

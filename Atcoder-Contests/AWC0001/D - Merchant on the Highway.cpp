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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vi a(n), b(n);
	rep(i, 0, n) {
		input(a[i], b[i]);
	}

	vector<vi> dp(n, vi(m + 1, 0));
	rep(i, 0, n) {
		dp[i][b[i]] = a[i];
		rep(j, max(0ll, i - k), i) {
			rep(x, b[i], m + 1) {
				dp[i][x] = max(dp[i][x], dp[j][x - b[i]] + a[i]);
			}
		}
	}
	int res = 0;
	rep(i, 0, n) {
		res = max(res, *max_element(all(dp[i])));
	}
	print(res);
}

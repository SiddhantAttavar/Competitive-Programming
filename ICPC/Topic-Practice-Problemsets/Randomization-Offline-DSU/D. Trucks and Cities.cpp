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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vi a(n);
	arrput(a);

	vector<vector<array<int, 3>>> v(n + 1);
	rep(i, 0, m) {
		int s, f, c, r;
		input(s, f, c, r);
		v[r].push_back({s - 1, f - 1, c});
	}

	int res = 0;
	vector<vi> dp(n, vi(n));
	rep(i, 0, n) {
		rep(j, i, n) {
			dp[i][j] = a[j] - a[i];
		}
	}
	for (auto [s, f, c] : v[0]) {
		res = max(res, c * dp[s][f]);
	}

	rep(x, 1, n + 1) {
		vector<vi> ndp(n, vi(n));
		rep(i, 0, n) {
			rep(j, i, n) {
				int l = i, r = j, k = j;
				while (l <= r) {
					int m = (l + r) / 2;
					if (dp[i][m] >= (a[j] - a[m])) {
						k = m;
						r = m - 1;
					}
					else {
						l = m + 1;
					}
				}
				ndp[i][j] = dp[i][k];
				if (k > i) {
					ndp[i][j] = min(ndp[i][j], a[j] - a[k - 1]);
				}
			}
		}

		swap(dp, ndp);
		for (auto [s, f, c] : v[x]) {
			res = max(res, c * dp[s][f]);
		}
	}
	print(res);
}

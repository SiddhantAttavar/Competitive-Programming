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
		int n, m;
		input(n, m);

		vector<vi> v(n, vi(m));
		rep(i, 0, n) {
			arrput(v[i]);
		}
		
		vi a(m);
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (v[i][j]) {
					a[j] = i;
				}
			}
		}

		vi dp(n);
		rep(i, 0, n) {
			dp[i] = abs(i - a[0]);
		}
		rep(j, 1, m) {
			vi ndp = dp;
			rep(i, 0, n) {
				if (i) {
					ndp[i] = min(ndp[i], dp[i - 1]);
				}
				if (i < n - 1) {
					ndp[i] = min(ndp[i], dp[i + 1]);
				}
				ndp[i] += abs(i - a[j]);
			}
			dp = ndp;
		}
		print(*min_element(all(dp)));
	}
}

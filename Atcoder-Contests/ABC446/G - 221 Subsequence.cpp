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
const int MOD = 998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	vi a(n);
	arrput(a);

	vector<vi> v(n + 1);
	vi dp(n + 1, 0), pdp(n + 1, 0);
	dp[0] = 1;
	pdp[0] = 1;
	rep(i, 0, n) {
		v[a[i]].push_back(i);
		if (sz(v[a[i]]) == a[i]) {
			int j = v[a[i]][sz(v[a[i]]) - a[i]];
			dp[i + 1] = pdp[j];
		}
		else if (sz(v[a[i]]) > a[i]) {
			int j = v[a[i]][sz(v[a[i]]) - a[i]];
			int k = v[a[i]][sz(v[a[i]]) - a[i] - 1];
			dp[i + 1] = (pdp[j] - pdp[k + 1] + MOD) % MOD;
		}
		pdp[i + 1] = (pdp[i] + dp[i + 1]) % MOD;
	}
	print((pdp[n] + MOD - 1) % MOD);
}

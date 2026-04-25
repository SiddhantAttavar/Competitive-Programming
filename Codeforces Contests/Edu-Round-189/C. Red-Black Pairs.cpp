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

int check(char a, char b) {
	return a != b;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string a, b;
		input(a, b);

		vi dp(n);
		dp[0] = check(a[0], b[0]);
		if (n >= 2) {
			dp[1] = min(check(a[0], b[0]) + check(a[1], b[1]), check(a[0], a[1]) + check(b[0], b[1]));
		}
		rep(i, 2, n) {
			dp[i] = min(
				dp[i - 1] + check(a[i], b[i]),
				dp[i - 2] + min(check(a[i - 1], b[i - 1]) + check(a[i], b[i]), check(a[i - 1], a[i]) + check(b[i - 1], b[i]))
			);
		}
		print(dp[n - 1]);
	}
}

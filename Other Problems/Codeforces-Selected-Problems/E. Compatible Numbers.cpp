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
	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	const int N = 1 << 22;
	vector<int> dp(N, -1);
	rep(i, 0, n) {
		dp[a[i]] = a[i];
	}
	rep(i, 0, N) {
		rep(j, 0, 22) {
			if (i >> j & 1 and dp[i ^ (1 << j)] != -1) {
				dp[i] = dp[i ^ (1 << j)];
			}
		}
	}

	rep(i, 0, n) {
		cout << dp[~a[i] & (N - 1)] << ' ';
	}
	cout << endl;
}

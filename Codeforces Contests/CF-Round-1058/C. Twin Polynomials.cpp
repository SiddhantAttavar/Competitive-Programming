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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n + 1);
		arrput(a);

		if (*max_element(a.begin(), a.end()) > n + 1) {
			print(0);
			continue;
		}

		bool flag = true;
		rep(i, 0, n) {
			if (a[i] == -1) {
				continue;
			}
			if (a[a[i]] == -1 and a[i] != 0) {
				a[a[i]] = i;
			}
			if (a[i] != 0 and a[a[i]] != i) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		int x = count(a.begin(), a.end(), -1);
		vector<int> dp(x + 1, 1);
		bool b = a[0] == -1;
		rep(i, 2, x + 1) {
			dp[i] = ((i - 1 - b) * dp[i - 2] + (1 + b) * dp[i - 1]) % MOD;
		}

		int res = dp[x];
		if (a[n] == -1 and a[0] == -1) {
			res = (res - dp[x - 1] + MOD) % MOD;
		}
		print(res);
	}
}

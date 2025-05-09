#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	int N = 1e3;
	vector<int> dp(N + 1, 0);
	rep(i, 1, N + 1) {
		int u = i;
		while (u != 1 and dp[i] < 100) {
			dp[i]++;
			if (u % 2 == 0) {
				u /= 2;
			}
			else {
				u = 3 * u + 1;
			}
		}
	}

	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int l, r, k;
			input(l, r, k);
			int res = 0;
			rep(i, l - 1, r) {
				res += dp[a[i]] >= k;
			}
			print(res);
		}
		else {
			int i;
			input(i);
			i--;
			vector<int> v(100, 0);
			a[i]++;
		}
	}
}

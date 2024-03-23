#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int k;
	input(k);

	string s;
	input(s);

	vector<int> dp((1 << k) - 1, 0);
	range(i, 0, 1 << (k - 1)) {
		dp[i] = 1 + (s[i] == '?');
	}
	range(i, 1 << (k - 1), (1 << k) - 1) {
		if (s[i] == '?' or s[i] == '0') {
			dp[i] = dp[(i << 1) ^ (1 << k)];
		}
		if (s[i] == '?' or s[i] == '1') {
			dp[i] += dp[(i << 1) ^ (1 << k) + 1];
		}
	}

	int q;
	input(q);
	while (q--) {
		int i;
		char c;
		input(i, c);

		i--;
		s[i] = c;

		while (i != (1 << k) - 1) {
			if (i < 1 << (k - 1)) {
				dp[i] = 1 + (s[i] == '?');
			}
			else {
				dp[i] = 0;
				if (s[i] == '?' or s[i] == '0') {
					dp[i] = dp[(i << 1) ^ (1 << k)];
				}
				if (s[i] == '?' or s[i] == '1') {
					dp[i] += dp[(i << 1) ^ (1 << k) + 1];
				}
			}
			i = (i >> 1) ^ (1 << (k - 1));
		}

		print(dp.back());
	}
}

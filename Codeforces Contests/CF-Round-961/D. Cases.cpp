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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c, k;
		input(n, c, k);

		string s;
		input(s);

		vector<int> b = {0};
		vector<int> a(c, 0);
		range(i, 0, k) {
			b[0] |= 1 << (s[i] - 'A');
			a[s[i] - 'A']++;
		}
		range(i, k, n) {
			b.push_back(b.back() | (1 << (s[i] - 'A')));
			a[s[i] - 'A']++;
			a[s[i - k] - 'A']--;
			if (a[s[i - k] - 'A'] == 0) {
				b.back() ^= 1 << (s[i - k] - 'A');
			}
		}

		range(i, 0, b.size()) {
			b[i] ^= (1 << c) - 1;
		}

		vector<bool> dp(1 << c, true);
		for (int i : b) {
			dp[i] = false;
		}

		int res = c;
		for (int i = (1 << c) - 1; i >= 0; i--) {
			if (dp[i]) {
				if (i & (1 << (s[n - 1] - 'A'))) {
					res = min(res, (int) __builtin_popcount(i));
				}
				continue;
			}

			range(j, 0, c) {
				dp[i ^ (1 << j)] = false;
			}
		}
		print(res);
	}
}

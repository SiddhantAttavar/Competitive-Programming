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
		int m, x;
		input(m, x);

		vector<int> c(m), h(m);
		range(i, 0, m) {
			input(c[i], h[i]);
		}

		int k = 0;
		for (int i : h) {
			k += i;
		}

		vector<int> dp(k + 1, 1e15);
		dp[0] = 0;
		range(i, 0, m) {
			int y = x * i - c[i];
			for (int j = k; j >= h[i]; j--) {
				if (dp[j - h[i]] <= y) {
					dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
				}
			}
		}

		for (int j = k; j >= 0; j--) {
			if (dp[j] != 1e15) {
				print(j);
				break;
			}
		}
	}
}

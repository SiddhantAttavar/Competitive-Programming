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
	int N = 2000;
	vector<int> dp(N + 1, 0);
	range(i, 1, N + 1) {
		set<int> s;
		for (int j = 1; j < (i - j); j++) {
			s.insert(dp[j] ^ dp[i - j]);
		}
		range(j, 0, s.size() + 1) {
			if (!s.count(j)) {
				dp[i] = j;
				break;
			}
		}
	}
	arrPrint(dp);
	range(i, 0, N + 1) {
		if (!dp[i]) {
			print(i);
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
	}
}

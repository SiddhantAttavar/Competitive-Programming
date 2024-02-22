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
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> l(m), r(m);
		range(i, 0, m) {
			input(l[i], r[i]);
		}

		map<int, vector<int>> s;
		map<int, int> c;
		range(i, 0, m) {
			s[r[i]].push_back(l[i]);
			c[l[i]]++;
		}

		vector<int> dp(n + 1, 0);
		multiset<int> z;
		range(i, 1, n + 1) {
			range(j, 0, c[i]) {
				z.insert(i);
			}	
			// arrPrint(z);
			dp[i] = dp[i - 1];
			if (!z.empty()) {
				dp[i] = max(dp[i], dp[*z.begin() - 1] + (int) z.size());
				// print(i, dp[*z.begin() - 1] + (int) z.size());
			}
			for (int j : s[i]) {
				z.erase(z.find(j));
			}
		}

		// arrPrint(dp);
		print(dp[n]);
	}
}

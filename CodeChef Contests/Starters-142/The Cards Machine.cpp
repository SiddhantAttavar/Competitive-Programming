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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> dp(n, 0);
		stack<int> s;
		map<int, int> m;
		range(i, 0, n) {
			while (!s.empty() and a[s.top()] <= a[i]) {
				s.pop();
			}

			if (s.empty()) {
				dp[i] = 0;
				if (m.count(a[i])) {
					dp[i] += m[a[i]] + 1;
				}
				s.push(i);
				m[a[i]] = i;
				continue;
			}

			int j = s.top();
			dp[i] = dp[j];
			if (m.count(a[i]) and m[a[i]] > j) {
				dp[i] += m[a[i]] - j;
			}
			s.push(i);
			m[a[i]] = i;
		}

		vector<int> pref(n + 1, 0);
		range(i, 0, n) {
			pref[i + 1] = pref[i] + dp[i];
		}

		int q;
		input(q);
		while (q--) {
			int k;
			input(k);

			print(pref[n - k]);
		}
	}
}

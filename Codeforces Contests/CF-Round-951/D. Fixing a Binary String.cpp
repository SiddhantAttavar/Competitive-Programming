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
		int n, k;
		input(n, k);

		string s;
		input(s);

		if (k == 1) {
			int x = 0;
			int p = -1;
			range(i, 1, n) {
				if (s[i] == s[i - 1]) {
					p = i;
					x++;
				}
			}
			if (x == 1) {
				print(p);
			}
			else if (x == 0 and n % 2 == 0) {
				print(n);
			}
			else {
				print(-1); 
			}
			continue;
		}

		vector<bool> a(n);
		range(i, 0, n) {
			a[i] = s[i] == '1';
		}

		vector<int> pref(n + 1, 0);
		range(i, 0, n) {
			pref[i + 1] = pref[i] + a[i];
		}

		vector<int> dp(n);
		range(i, 0, k) {
			dp[i] = i;
		}
		range(i, k - 1, n) {
			int x = pref[i + 1] - pref[i - k + 1];
			if (x > 0 and x < k) {
				dp[i] = i;
			}
			else if ((x == 0 and a[i - k]) or (x == k and !a[i - k])) {
				dp[i] = i == k - 1 ? -1 : dp[i - k];
			}
			else {
				dp[i] = i == i - k;
			}
		}
		// arrPrint(dp);

		int res = -1;
		if ((pref[n] == 0 or pref[n] == n) and n == k) {
			print(n);
			continue;
		}
		range(p, 1, n + 1) {
			int x = (n - p) % k;
			int y = k - x;

			if (p > n - x) {
				continue;
			}

			if (a[n - 1] != a[p - 1]) {
				continue;
			}

			if (a[n - x] == a[n - x - 1]) {
				continue;
			}

			if (p != y and a[p - y] == a[p - y - 1]) {
				continue;
			}

			if (p < y) {
				continue;
			}

			if (dp[n - x - 1] >= p) {
				continue;
			}

			if (p != y and dp[p - y - 1] != -1) {
				continue;
			}

			int t = pref[p] - pref[p - y] + pref[n] - pref[n - x];
			if (t == 0 or t == k) {
				res = p;
				break;
			}
		}
		print(res);
	}
}

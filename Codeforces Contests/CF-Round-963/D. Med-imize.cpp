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

bool solve(vector<int> &a, int k, int m) {
	int n = a.size();

	int r = n % k, c = (n + k - 1) / k;
	if (r == 0) {
		r = k;
	}
	vector<vector<int>> dp(r, vector<int>(c, 0));
	dp[0][0] = a[0] >= m;
	range(j, 1, c) {
		dp[0][j] = max((int) (a[j * k] >= m), dp[0][j - 1]);
	}
	range(i, 1, r) {
		dp[i][0] = (a[i] >= m) + dp[i - 1][0];
		range(j, 1, c) {
			dp[i][j] = max(dp[i][j - 1], (a[i + j * k] >= m) + dp[i - 1][j]);
		}
	}

	return 2 * dp[r - 1][c - 1] > r;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		int l = *min_element(a.begin(), a.end()), r = *max_element(a.begin(), a.end()), res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (solve(a, k, m)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}

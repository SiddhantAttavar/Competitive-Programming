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
	int N = 2e6;

	vector<int> spf(N + 1), primes = {0};
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		primes.push_back(i);

		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	vector<int> dp(N + 1, 0);
	range(i, 2, N + 1) {
		dp[i] = dp[i / spf[i]] + 1;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<int> a(n);
		arrPut(a);

		int x = 0, y = 0;
		for (int i : a) {
			if (dp[i] > x) {
				y = x;
				x = dp[i];
			}
			else if (dp[i] > y) {
				y = dp[i];
			}
		}

		int q = 0;
		for (int i : a) {
			q += i;
		}

		int p = primes[upper_bound(primes.begin(), primes.end(), m) - primes.begin() - 1];

		int res = 0;
		range(i, p, m + 1) {
			if (k == 1) {
				res = max(res, q + k * i - x - max(dp[i], y));
			}
			else {
				res = max(res, q + k * i - max(x, dp[i]) - max(dp[i], y));
			}
		}

		print(res);
	}
}

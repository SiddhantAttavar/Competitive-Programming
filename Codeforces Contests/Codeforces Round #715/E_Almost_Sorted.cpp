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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
	int N = 60;
	vector<int> dp(N + 1, 1);
	int x = 1;
	range(i, 0, N) {
		dp[i + 1] = x;
		x += dp[i + 1];
	}
 
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> res;
		int t = min(n - 1, 60ll);
		range(i, 1, n - t) {
			res.push_back(i);
		}

		bool flag = true;
		range(i, n - t - 1, n) {
			int u = i;
			while (u < n) {
				if (k <= dp[n - u - 1]) {
					break;
				}
				k -= dp[n - u - 1];
				u++;
			}

			if (u == n) {
				flag = false;
				break;
			}

			for (int j = u; j >= i; j--) {
				res.push_back(j + 1);
			}
			i = u;
		}

		if (flag) {
			arrPrint(res);
		}
		else {
			print(-1);
		}
	}
}

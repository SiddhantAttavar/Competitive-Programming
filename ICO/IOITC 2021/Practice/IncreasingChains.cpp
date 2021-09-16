#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int main() {
	setup();

	int n, k; input(n, k);
	int a[n]; arrPut(a);

	int dp[n][n];
	range(i, 0, n) {
		fill(dp[i], dp[i] + n, -1);
	}

	dp[0][0] = 1;
	range(i, 1, n) {
		dp[i][0] = 1;
		range(j, k - 1, n) {
			range(l, 0, i) {
				if (dp[l][j] != -1) {
					dp[i][0] = max(dp[i][0], dp[l][j] + 1);
				}	
			}
		}
		
		range(j, 1, n) {
			range(l, 0, i) {
				if (a[l] <= a[i] && dp[l][j - 1] != -1) {
					dp[i][j] = max(dp[i][j], dp[l][j - 1] + 1);
				}
			}
		}
	}

	int res = 0;
	range(i, 0, n) {
		range(j, k - 1, n) {
			res = max(res, dp[i][j]);
		}
	}
	print(res);
}
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> dp(1 << n, 0);
	dp[0] = 1;
	range(j, 0, m) {
		range(i, 0, n) {
			vector<int> ndp(1 << n);
			range(k, 0, 1 << n) {
				ndp[k] = dp[k ^ (1 << i)];

				if (i and !(k & (1 << i)) and !(k & (1 << (i - 1)))) {
					ndp[k] = (ndp[k] + dp[k ^ (1 << (i - 1))]) % MOD;
				}
			}

			dp = ndp;
		}
	}

	print(dp[0]);
}

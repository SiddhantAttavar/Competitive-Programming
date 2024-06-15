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
const int MOD = 998244353;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return (a * mod_pow(b, MOD - 2)) % MOD;
}

int32_t main() {
	setup();

	int k;
	input(k);

	vector<int> c(26);
	arrPut(c);

	vector<int> fact(k + 1, 1);
	range(i, 1, k + 1) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	vector<vector<int>> dp(k + 1, vector<int>(26, 0));
	dp[0] = vector<int>(26, 1);
	range(x, 1, k + 1) {
		dp[x][0] = c[0] >= x;
		range(i, 1, 26) {
			range(j, 0, min((int) x, c[i]) + 1) {
				dp[x][i] = (dp[x][i] + mod_div((fact[x] * dp[x - j][i - 1]) % MOD, (fact[j] * fact[x - j]) % MOD)) % MOD;
			}
		}
	}

	int res = 0;
	range(i, 1, k + 1) {
		res = (res + dp[i][25]) % MOD;
	}
	print(res);
}

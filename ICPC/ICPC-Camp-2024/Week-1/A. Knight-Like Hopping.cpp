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
	setup();

	vector<vector<int>> graph = {
		{4, 6},
		{6, 8},
		{7, 9},
		{4, 8},
		{3, 9, 0},
		{},
		{1, 7, 0},
		{2, 6},
		{1, 3},
		{2, 4},
	};

	int n, m, o;
	input(n, m, o);

	string t;
	input(t);

	string s;
	vector<vector<int>> pref(m, vector<int>(10, 0));
	range(i, 0, m) {
		s += t[i];
		range(j, 0, 10) {
			string c = s;
			c.back() = j + '0';
			int l = 0;
			for (int k = i + 1; k > 0; k--) {
				if (s.substr(0, k) == c.substr(i + 1 - k, k)) {
					pref[i][j] = k;
					break;
				}
			}
		}
	}

	vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(10, 0));
	range(k, 0, 10) {
		dp[0][k] = 1;
	}
	range(j, 0, m - 1) {
		dp[j + 1][t[j] - '0'] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		vector<vector<int>> ndp = vector<vector<int>>(m + 1, vector<int>(10, 0));
		range(j, 0, m) {
			range(k, 0, 10) {
				for (int u : graph[k]) {
					ndp[j][k] = (ndp[j][k] + dp[pref[j][u]][u]) % MOD;
				}
			}
		}

		if (m == 0) {
			range(k, 0, 10) {
				for (int u : graph[k]) {
					ndp[0][k] = (ndp[0][k] + dp[0][u]) % MOD;
				}
			}
		}

		dp = ndp;
	}

	print(dp[0][o]);
}

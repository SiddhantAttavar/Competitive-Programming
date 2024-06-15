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
	setup();

	int n, m, k;
	input(n, m, k);

	if (k < n or k > n * m) {
		print("No");
		return 0;
	}

	print("Yes");
	vector<vector<int>> dp(n + 1, vector<int>(m, 0));
	range(i, 1, n + 1) {
		if (i % 2) {
			dp[i][0] = dp[i - 1][0] + 1;
			range(j, 1, m) {
				dp[i][j] = dp[i][j - 1] + 1;
			}
		}
		else {
			dp[i][m - 1] = dp[i - 1][m - 1] + 1;
			for (int j = m - 2; j >= 0; j--) {
				dp[i][j] = dp[i][j + 1] + 1;
			}
		}
	}

	pair<int, int> p = {-1, -1};
	range(i, 0, n) {
		range(j, 0, m) {
			if (dp[i + 1][j] + (n - i - 1) == k) {
				p = {i, j};
				break;
			}
		}
	}

	vector<string> res(2 * n + 1, string(2 * m + 1, '+'));
	for (int i = 1; i < 2 * n; i += 2) {
		for (int j = 1; j <= 2 * m; j += 2) {
			res[i][j] = 'o';
		}
		for (int j = 2; j < 2 * m; j += 2) {
			res[i][j] = '.';
		}
	}
	for (int i = 2; i < 2 * n; i += 2) {
		for (int j = 1; j <= 2 * m; j += 2) {
			res[i][j] = '-';
		}
	}
	range(i, 0, p.first) {
		if (i % 2 == 0) {
			res[2 * i + 2][2 * m - 1] = '.';
		}
		else {
			res[2 * i + 2][1] = '.';
		}
	}
	res[2 * p.first + 2][2 * p.second + 1] = '.';
	range(i, p.first + 1, n) {
		range(j, 0, m - 1) {
			res[2 * i + 1][2 * j + 2] = '|';
		}
		res[2 * i + 2][2 * p.second + 1] = '.';
	}

	res[0][1] = 'S';
	res[2 * n][2 * p.second + 1] = 'G';

	if (p.first) {
		if (p.first % 2 == 1 and p.second > 0) {
			res[2 * p.first + 1][2 * p.second] = '|';
		}
		else if (p.first % 2 == 0 and p.second < m - 1) {
			res[2 * p.first + 1][2 * p.second + 2] = '|';
		}
	}

	for (string s : res) {
		print(s);
	}
}

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

int32_t main() {
	setup();
	
	int n, m;
	input(n, m);

	vector<vector<int>> a(n, vector<int>(m));
	range(i, 0, n) {
		arrPut(a[i]);
	}

	vector<vector<int>> dp1(n + 2, vector<int>(m + 2));
	range(i, 1, n + 1) {
		range(j, 1, m + 1) {
			dp1[i][j] = a[i - 1][j - 1] + max(dp1[i - 1][j], dp1[i][j - 1]);
		}
	}

	vector<vector<int>> dp2(n + 2, vector<int>(m + 2));
	range(i, 1, n + 1) {
		for (int j = m; j > 0; j--) {
			dp2[i][j] = a[i - 1][j - 1] + max(dp2[i - 1][j], dp2[i][j + 1]);
		}
	}
	
	vector<vector<int>> dp3(n + 2, vector<int>(m + 2));
	for (int i = n; i > 0; i--) {
		range(j, 1, m + 1) {
			dp3[i][j] = a[i - 1][j - 1] + max(dp3[i + 1][j], dp3[i][j - 1]);
		}
	}
	
	vector<vector<int>> dp4(n + 2, vector<int>(m + 2));
	for (int i = n; i > 0; i--) {
		for (int j = m; j > 0; j--) {
			dp4[i][j] = a[i - 1][j - 1] + max(dp4[i + 1][j], dp4[i][j + 1]);
		}
	}
	
	int res = 0;
	range(i, 2, n) {
		range(j, 2, m) {
			res = max({
				res,
				(dp1[i - 1][j] + dp4[i + 1][j]) + (dp2[i][j + 1] + dp3[i][j - 1]),
				(dp1[i][j - 1] + dp4[i][j + 1]) + (dp2[i - 1][j] + dp3[i + 1][j]),
			});
		}
	}

	print(res);
}

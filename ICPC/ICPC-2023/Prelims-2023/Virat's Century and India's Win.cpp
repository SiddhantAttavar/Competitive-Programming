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
map<tuple<int, int, int, int>, int> m;

int modPow(int a, int b) {
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

int solve(int i, int j, int a, int b) {
	tuple<int, int, int, int> t = {i, j, a, b};
	if (m.count(t)) {
		return m[t];
	}

	if (i <= 0) {
		return true;
	}

	if (j == 0) {
		return false;
	}

	if (j % 6 == 1) {
		swap(a, b);
	}

	return m[t] = modDiv((
		solve(i - 1, j - 1, b, a) +
		solve(i - 2, j - 1, a, b) +
		solve(i - 3, j - 1, b, a) +
		solve(i - 4, j - 1, a, b) +
		solve(i - 6, j - 1, a, b) +
		(j % 6 == 1 ? solve(i, j - 1, a, max(a, b) + 1) : solve(i, j - 1, max(a, b) + 1, b)) * (j % 6 == 1 ? b != 0 : a != 0)
	) % MOD, 6);
}

int dp[151][61][11][101][2][2];
int INV_6;

int32_t main() {
	INV_6 = modPow(6, MOD - 2);
	range(j, 0, 61) {
		range(k, 0, 11) {
			dp[0][j][k][0][0][0] = 1;
			dp[0][j][k][0][1][0] = 1;
		}
	}

	range(j, 1, 61) {
		range(i, 1, 151) {
			range(k, 1, 11) {
				range(l, 0, 101) {
					dp[i][j][k][l][0][0] = 0;
					dp[i][j][k][l][0][0] = 0;
				}
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, b, w, x;
		input(n, b, w, x);

		print(solve(n, b, 0, 11 - w));
	}
}

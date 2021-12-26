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
#define int long long

int32_t main() {
	setup();
	
	int n, m; input(n, m);
	int prefSum[n + 1][m + 1];
	range(i, 0, n) {
		prefSum[i][0] = 0;
	}
	range(j, 1, m) {
		prefSum[0][j] = 0;
	}
	range(i, 0, n) {
		range(j, 0, m) {
			input(prefSum[i + 1][j + 1]);
			prefSum[i + 1][j + 1] += prefSum[i][j + 1] + prefSum[i + 1][j] - prefSum[i][j];
		}
	}

	int q; input(q);
	while (q--) {
		int a, b, c, d; input(a, b, c, d);
		int x = prefSum[c][d] - prefSum[a - 1][d] - prefSum[c][b - 1] + prefSum[a - 1][b - 1];
		print(x == (c - a + 1) * (d - b + 1));
	}
}

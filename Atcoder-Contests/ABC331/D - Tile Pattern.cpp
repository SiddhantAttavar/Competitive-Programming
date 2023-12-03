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

int count(int a, int b, int c, int d, vector<vector<int>> &p, int n) {
	if (a > c or b > d) {
		return 0;
	}

	if (a / n != c / n) {
		return (
			count(a % n, b, n - 1, d, p, n) +
			count(0, b, c % n, d, p, n)
		);
	}

	if (b / n != d / n) {
		return (
			count(a, b % n, c, n - 1, p, n) +
			count(a, 0, c, d % n, p, n)
		);
	}

	a %= n;
	b %= n;
	c %= n;
	d %= n;
	// print(a, b, c, d);

	return p[c + 1][d + 1] - p[a][d + 1] - p[c + 1][b] + p[a][b];
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<string> x(n);
	arrPut(x);

	vector<vector<int>> p(n + 1, vector<int>(n + 1));
	range(i, 0, n) {
		range(j, 0, n) {
			p[i + 1][j + 1] = (x[i][j] == 'B') + p[i + 1][j] + p[i][j + 1] - p[i][j];
		}
	}
	// print(count(3, 3, 4, 5, p, n));

	while (q--) {
		int a, b, c, d;
		input(a, b, c, d);

		int k = (c - a + 1) / n;
		int l = (d - b + 1) / n;

		print(
			k * l * p[n][n] +
			k * count(a, b + n * l, a + n - 1, d, p, n) +
			l * count(a + n * k, b, c, b + n - 1, p, n) +
			count(a + n * k, b + n * l, c, d, p, n)
		);
	}
}

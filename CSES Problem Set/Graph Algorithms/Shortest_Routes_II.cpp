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

	int n, m, q;
	input(n, m, q);

	vector<vector<int>> d(n, vector<int>(n, 1e18));
	range(i, 0, n) {
		d[i][i] = 0;
	}
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		d[u - 1][v - 1] = min(d[u - 1][v - 1], w);
		d[v - 1][u - 1] = min(d[v - 1][u - 1], w);
	}

	range(k, 0, n) {
		range(i, 0, n) {
			range(j, 0, n) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	while (q--) {
		int u, v;
		input(u, v);

		if (d[u - 1][v - 1] == (int) 1e18) {
			print(-1);
		}
		else {
			print(d[u - 1][v - 1]);
		}
	}
}

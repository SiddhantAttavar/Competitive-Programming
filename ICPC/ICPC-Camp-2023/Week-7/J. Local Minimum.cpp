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

	vector<int> x(n), y(m);
	range(i, 0, n) {
		x[i] = *min_element(a[i].begin(), a[i].end());
	}
	range(j, 0, m) {
		int x = 1e9;
		range(i, 0, n) {
			x = min(x, a[i][j]);
		}
		y[j] = x;
	}

	int res = 0;
	range(i, 0, n) {
		range(j, 0, m) {
			res += a[i][j] == min(x[i], y[j]);
		}
	}
	print(res);
}

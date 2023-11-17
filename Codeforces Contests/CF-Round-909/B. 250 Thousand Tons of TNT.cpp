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

int solve(int n, int x, vector<int> &a) {
	int mi = 1e18, ma = 0;
	for (int j = 0; j < n; j += x) {
		int s = 0;
		range(i, j, j + x) {
			s += a[i];
		}
		mi = min(mi, s);
		ma = max(ma, s);
	}

	return ma - mi;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int res = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				res = max({res, solve(n, i, a), solve(n, n / i, a)});
			}
		}

		print(res);
	}
}

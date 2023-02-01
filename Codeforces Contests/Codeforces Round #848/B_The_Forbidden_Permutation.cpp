#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, d;
		input(n, m, d);

		vector<int> p(n);
		arrPut(p);

		vector<int> a(m);
		arrPut(a);

		vector<int> pos(n + 1, -1);
		range(i, 0, n) {
			pos[p[i]] = i;
		}

		int res = 1e9;
		range(i, 0, m - 1) {
			int x = pos[a[i]], y = pos[a[i + 1]];
			int u = y - x;
			int v = (d + 1) - (y - x);

			if ((u < 0) or (v < 0)) {
				res = 0;
				break;
			}

			res = min(res, u);
			if ((n - y) + x > v) {
				res = min(res, v);
			}
		}

		print(res);
	}
}

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
	setup(); int tc; input(tc); while (tc--) {
		int n, k, a, b;
		input(n, k, a, b);
		a--;
		b--;

		vector<int> x(n), y(n);
		range(i, 0, n) {
			input(x[i], y[i]);
		}

		int p = 1e18, q = 1e18;
		range(i, 0, k) {
			p = min(p, abs(x[a] - x[i]) + abs(y[a] - y[i]));
			q = min(q, abs(x[b] - x[i]) + abs(y[b] - y[i]));
		}

		print(min(p + q, abs(x[a] - x[b]) + abs(y[a] - y[b])));
	}
}

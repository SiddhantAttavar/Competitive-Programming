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

bool check(int n, int p, int l, int t, int x) {
	int res = x * l;
	int i = (n - x + 6) / 7;
	int j = (n + 6) / 7 - i;
	res += t * min(2 * x, i + j);
	return res >= p;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, p, l, t;
		input(n, p, l, t);

		int a = 0, b = n, res = -1;
		while (a <= b) {
			int m = (a + b) / 2;
			if (check(n, p, l, t, m)) {
				res = n - m;
				b = m - 1;
			}
			else {
				a = m + 1;
			}
		}

		print(res);
	}
}

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
		int x, y, k;
		input(x, y, k);

		int res = x + y;
		range(i, 0, k) {
			int ox = x, oy = y;
			if (x > y) {
				swap(x, y);
			}
			y = __gcd(x, y);
			res = min(res, x + y);

			if (x == 1 and y == 1) {
				break;
			}

			if (x == ox and y == oy) {
				break;
			}
		}
		print(res);
	}
}

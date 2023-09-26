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

bool check(__int128 a, __int128 b, __int128 c, __int128 k) {
	__int128 x = (k + 2) / 2;
	a = min(a, b);
	
}

int32_t main() {
	setup(); int tc; input(tc); range(t, 1, tc + 1) {
		int a, b, c;
		input(a, b, c);

		int l = 0, r = 1e18, res = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(a, b, c, m)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}

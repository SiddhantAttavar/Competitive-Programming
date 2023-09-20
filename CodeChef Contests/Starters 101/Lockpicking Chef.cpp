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
		int n, m;
		input(n, m);

		string s, k;
		input(s, k);

		int res = 1e9;
		range(i, 0, n - m + 1) {
			int c = 0;
			range(j, 0, m) {
				int x = min(s[i + j] - '0', k[j] - '0');
				int y = max(s[i + j] - '0', k[j] - '0');
				c += min(y - x, x + 10 - y);
			}
			res = min(res, c);
		}
		print(res);
	}
}

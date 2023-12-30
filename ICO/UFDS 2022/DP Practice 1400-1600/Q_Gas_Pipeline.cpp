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
		int n, a, b;
		input(n, a, b);

		string s;
		input(s);

		s.push_back('0');

		vector<int> f(n + 1), g(n + 1);
		f[0] = b;
		g[0] = 1e18;
		range(i, 1, n + 1) {
			g[i] = min(
				f[i - 1] + a,
				g[i - 1]
			) + a + 2 * b;

			if (s[i] == '1' or s[i - 1] == '1') {
				f[i] = 1e18;
			}
			else {
				f[i] = min(
					f[i - 1],
					g[i - 1] + a
				) + a + b;
			}
		}

		print(f[n]);
	}
}

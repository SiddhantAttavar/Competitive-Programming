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
	int N = 1e6;
	int MOD = (int) 1e9 + 7;

	vector<int> f(N + 1), g(N + 1);
	f[1] = 1;
	g[1] = 1;

	range(i, 2, N + 1) {
		f[i] = (2 * f[i - 1] + g[i - 1]) % MOD;
		g[i] = (4 * g[i - 1] + f[i - 1]) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		print((f[n] + g[n]) % MOD);
	}
}

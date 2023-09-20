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

const __int128 MOD = (int) 1e9 + 7;

int solve(int n, int l, int r) {
	if (n == 1) {
		return 1;
	}

	if (r < l) {
		return 0;
	}

	int m = n / 2;
	if (r <= m) {
		return (((2 * solve(m, l, r) - (r - l + 1)) % MOD) + MOD) % MOD;
	}

	if (l > m) {
		return (((2 * solve(m, l - m, r - m)) % MOD) + MOD) % MOD;
	}

	__int128 x = ((__int128) (m * (m + 1)) / 2) % MOD;
	if ((r - m) < l) {
		return (((2 * (x - solve(m, r - m + 1, l - 1)) - (m - l + 1)) % MOD) + MOD) % MOD;
	}

	return (((2 * (x + solve(m, l, r - m)) - (m - l + 1)) % MOD) + MOD) % MOD;
}

int32_t main() {
	setup();

	// __int128 x = 30, y = 60;
	// __int128 t = (1 << x);
	// print(t * t == (1 << y));
	// print((int) (t * t), (int) (1 << y));

	int tc; input(tc); while (tc--) {
		int n, l, r;
		input(n, l, r);

		print(solve(n, l, r));
	}
}

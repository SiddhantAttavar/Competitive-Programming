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

int solve(int n, int k) {
	if (n == 1) {
		return 1;
	}

	if (k <= n / 2) {
		return 2 * k;
	}

	if (n % 2 == 1) {
		return 2 * ((solve(n / 2 + 1, k - n / 2) + n / 2 - 1) % (n / 2 + 1)) + 1;
	}

	return 2 * solve(n / 2, k - n / 2) - 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		print(solve(n, k));
	}
}

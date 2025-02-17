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

int solve(int n) {
	if (n <= 2) {
		return n;
	}

	if (n % 2 == 0) {
		int x = solve(n / 2);

		if (x == 1) {
			return n;
		}
		else {
			return 2 * (x - 1);
		}
	}

	int x = solve(n - 1);
	if (x == 1) {
		return 2;
	}

	if (x == n - 1) {
		return 1;
	}

	return x + 2;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		range(i, 0, n) {
			cout << solve(a[i]) << ' ';
		}

		cout << endl;
	}
}

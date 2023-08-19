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
		int m, k, a, b;
		input(m, k, a, b);

		// use as many k coins as possible
		m -= min(b, m / k) * k;

		// make divisible by k
		int x = min(a, m % k);
		int res = max(0ll, m % k - x);
		m -= m % k;
		a -= x;

		// use remaining 1 coins if possible
		m = max(0ll, m - k * (a / k));

		// make m 0
		res += m / k;
		m = 0;

		print(res);
	}
}

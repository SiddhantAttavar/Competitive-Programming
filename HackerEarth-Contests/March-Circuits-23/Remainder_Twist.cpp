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

int f(int x, int n) {
	int res = 0;
	range(b, x, n + 1) {
		res += (b - x) * (n / b) + max(0ll, n % b - x + 1);
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, r;
		input(n, r);

		int a = 1, b = n, res = -1;
		while (a <= b) {
			int x = (a + b) / 2;
			if (f(x, n) >= r) {
				res = x;
				a = x + 1;
			}
			else {
				b = x - 1;
			}
		}

		if (res == -1 and n * n >= r) {
			res = 0;
		}
		
		print(res);
	}
}

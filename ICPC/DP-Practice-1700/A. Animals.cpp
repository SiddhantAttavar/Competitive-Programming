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
	setup();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

	int n, x;
	input(n, x);

	int c[n];
	arrPut(c);

	range(i, 0, n) {
		c[i] *= n - i;
	}
	sort(c, c + n);

	int res = 0;
	range(i, 0, n) {
		if (x >= c[i]) {
			x -= c[i];
			res++;
		}
		else {
			break;
		}
	}

	print(res);
}

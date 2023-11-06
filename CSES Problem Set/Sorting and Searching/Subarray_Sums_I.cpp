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

	int n, x;
	input(n, x);

	vector<int> a(n);
	arrPut(a);

	int l = 0, res = 0, c = a[0];

	if (a[0] == x) {
		res++;
	}
	else if (a[0] > x) {
		l++;
		c -= a[0];
	}

	range(i, 1, n) {
		c += a[i];
		while (c > x) {
			c -= a[l];
			l++;
		}

		res += c == x;
	}

	print(res);
}

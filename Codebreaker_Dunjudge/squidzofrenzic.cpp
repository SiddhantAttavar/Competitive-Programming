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

bool check(int n, int m, int x, vector<int> &b) {
	if (m > n) {
		return false;
	}

	int c = 0;
	int res = 0;
	range(i, 0, n) {
		if (b[i] > x) {
			return false;
		}

		if (c + b[i] > x) {
			res++;
			c = 0;
		}
		c += b[i];
	}
	return res < m;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> b(n);
	arrPut(b);

	int res = 1e9;
	int l = 1, r = 1e9;
	while (l <= r) {
		int x = (l + r) / 2;
		if (check(n, m, x, b)) {
			res = x;
			r = x - 1;
		}
		else {
			l = x + 1;
		}
	}
	print(res);
}

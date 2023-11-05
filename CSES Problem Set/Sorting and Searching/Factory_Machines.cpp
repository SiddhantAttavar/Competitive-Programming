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

bool check(int x, vector<int> &a, int t) {
	__int128_t res = 0;
	for (int i : a) {
		res += x / i;
	}
	return res >= t;
}

int32_t main() {
	setup();

	int n, t;
	input(n, t);

	vector<int> a(n);
	arrPut(a);

	int l = 0, r = 1e18, res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m, a, t)) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1:
		}
	}

	print(res);
}

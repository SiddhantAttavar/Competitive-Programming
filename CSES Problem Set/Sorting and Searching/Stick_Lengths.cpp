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

int solve(vector<int> &p, int x) {
	int res = 0;
	for (int i : p) {
		res += abs(i - x);
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> p(n);
	arrPut(p);
	
	int l = 0, r = 1e9, res = 0;
	while (l <= r) {
		int a = l + (r - l) / 3;
		int b = r - (r - l) / 3;
		int x = solve(p, a);
		int y = solve(p, b);

		if (x == y) {
			res = x;
			l = a + 1;
			r = b - 1;
		}
		else if (x < y) {
			res = x;
			r = b - 1;
		}
		else {
			res = y;
			l = a + 1;
		}
	}
	print(res);
}

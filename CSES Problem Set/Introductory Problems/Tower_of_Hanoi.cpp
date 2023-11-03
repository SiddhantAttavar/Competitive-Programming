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

void solve(int n, int a, int b, int c, vector<pair<int, int>> &res) {
	if (n == 0) {
		return;
	}

	solve(n - 1, a, c, b, res);
	res.push_back({a, b});
	solve(n - 1, c, b, a, res);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<pair<int, int>> res;
	solve(n, 0, 2, 1, res);

	print(res.size());
	for (pair<int, int> p : res) {
		print(p.first + 1, p.second + 1);
	}
}

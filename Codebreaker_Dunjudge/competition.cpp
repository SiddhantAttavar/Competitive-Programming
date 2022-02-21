// https://codebreaker.xyz/problem/competition
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
	
	int n, a, b;
	input(n, a, b);

	vector<pair<int, int>> x(n);
	range(i, 0, n) {
		input(x[i].first);
	}
	range(i, 0, n) {
		input(x[i].second);
	}
	sort(x.begin(), x.end(), [](pair<int, int> x, pair<int, int> y) {
		return (x.first - x.second) < (y.first - y.second);
	});

	int res = 0;
	range(i, 0, b) {
		res += x[i].second;
	}
	range(i, b, n) {
		res += x[i].first;
	}
	print(res);
}

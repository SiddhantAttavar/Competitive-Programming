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

int solve(int i, int j, set<pair<int, int>> m, string &s) {
	if (i == 0 and j == 6) {
		return 1;
	}

	int res = 0;
	vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	for (pair<int, int> p : d) {
		int x = i + p.first, y = j + p.second;
		
		if (m.count({x, y})) {
			continue;
		}

		if (x < 0 or y < 0 or x >= 7 or y >= 7) {
			continue;
		}
		
		set<pair<int, int>> v(m);
		v.insert({x, y});
		res += solve(x, y, v, s);
	}
	return res;
}

int32_t main() {
	setup();

	string s;
	input(s);

	set<pair<int, int>> m;
	print(solve(0, 0, m, s));
}

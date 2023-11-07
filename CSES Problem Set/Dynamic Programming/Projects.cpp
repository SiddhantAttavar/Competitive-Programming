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

	int n;
	input(n);

	vector<pair<pair<int, int>, int>> v(n);
	range(i, 0, n) {
		input(v[i].first.second, v[i].first.first, v[i].second);
	}
	sort(v.begin(), v.end());

	map<int, int> m;
	m[0] = 0;
	range(i, 0, n) {
		map<int, int>::iterator j = m.lower_bound(v[i].first.second);
		j--;
		m[v[i].first.first] = max((*j).second + v[i].second, (*m.rbegin()).second);
	}

	print((*m.rbegin()).second);
}

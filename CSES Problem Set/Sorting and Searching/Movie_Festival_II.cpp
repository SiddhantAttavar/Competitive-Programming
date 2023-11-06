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

	int n, k;
	input(n, k);

	vector<pair<int, int>> v(n);
	range(i, 0, n) {
		input(v[i].second, v[i].first);
	}
	sort(v.begin(), v.end());

	multiset<int> m;
	range(i, 0, k) {
		m.insert(0);
	}

	int res = 0;
	for (pair<int, int> p : v) {
		// print(p.second, p.first);
		// arrPrint(m);
		// cout.flush();
		multiset<int>::iterator x = m.upper_bound(p.second);
		if (x == m.begin()) {
			continue;
		}
		x--;
		if (*x <= p.second) {
			res++;
			m.erase(x);
			m.insert(p.first);
		}
	}

	print(res);
}

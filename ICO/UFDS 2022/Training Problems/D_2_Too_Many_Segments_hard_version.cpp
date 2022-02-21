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

	vector<tuple<int, bool, int>> a(2 * n);
	vector<int> l(n), r(n);
	range(i, 0, n) {
		input(l[i], r[i]);
		a[2 * i] = {l[i], true, i};
		a[2 * i + 1] = {r[i] + 1, false, i};
	}
	sort(a.begin(), a.end());

	set<int> res;
	set<pair<int, int>> m;
	for (tuple<int, bool, int> t : a) {
		int x, i;
		bool b;
		tie(x, b, i) = t;
		// print(x, b, i);
		if (b) {
			m.insert({r[i], i});
			if (m.size() > k) {
				int i = (*m.rbegin()).second;
				// print(r[i], i);
				m.erase({r[i], i});
				res.insert(i + 1);
			}
		}
		else {
			// print("m");
			// for (pair<int, int> p : m) {
			// 	print(p.first, p.second);
			// }
			// print(x - 1, i);
			m.erase({r[i], i});
		}
	}
	print(res.size());
	arrPrint(res);
}

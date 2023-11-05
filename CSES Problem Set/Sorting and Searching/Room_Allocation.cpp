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

	vector<pair<int, pair<int, bool>> v;
	range(i, 0, n) {
		int a, b;
		input(a, b);

		v.push_back({a, {i, false}});
		v.push_back({b, {i, true}});
	}

	sort(v.begin(), v.end());

	int j = 0;
	set<int> s;
	vector<int> a(n);
	for (pair<int, pair<int, bool>> p : v) {
		int x = p.first, i = p.second.first;
		if (!p.second.second) {
			if (s.empty()) {
				j++;
				v[i] = j;
			}
			else {
				v[i] = *s.begin();
				s.erase(s.begin());
			}
		}
		else {
			s.insert(v[i]);
		}
	}

	print(j);
}

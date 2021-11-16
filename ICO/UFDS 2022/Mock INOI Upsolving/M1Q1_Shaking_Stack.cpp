#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int n, q; input(n, q);
	int i = 0;
	stack<int> s;
	map<int, pair<int, int>> m;
	while (n--) {
		int t; input(t);
		if (t == 1) {
			int x; input(x);
			s.push(x);
			m[x] = {i, i};
			i++;
		}
		else {
			int x = s.top();
			s.pop();
			m[x].second = i;
		}
	}
	while (!s.empty()) {
		int x = s.top();
		s.pop();
		m[x].second = i;
	}
	while (q--) {
		int a, b; input(a, b);
		if (m.find(a) == m.end() or m.find(b) == m.end()) {
			print(0);
			continue;
		}
		//print(m[a].first, m[a].second, m[b].first, m[b].second);
		print(max(0ll, 
			min(m[a].second, m[b].second) - 
			max(m[a].first, m[b].first)
		));
	}
}
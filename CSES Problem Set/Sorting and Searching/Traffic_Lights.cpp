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

	int x, n;
	input(x, n);

	vector<int> p(n);
	arrPut(p);

	priority_queue<pair<int, int>> pq;
	pq.push({x, 0});
	set<int> s;
	s.insert(0);
	s.insert(x);

	for (int i : p) {
		set<int>::iterator j = s.lower_bound(i);
		pq.push({*j - i, i});
		j--;
		pq.push({i - *j, *j});
		s.insert(i);

		while (!pq.empty()) {
			int d, l;
			tie(d, l) = pq.top();
			int r = l + d;

			set<int>::iterator y = s.find(r);
			y--;
			if (*y == l) {
				cout << d << ' ';
				break;
			}

			pq.pop();
		}
	}
}

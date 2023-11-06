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

	vector<pair<pair<int, int>, int>> e;
	multiset<int> a;
	range(i, 0, n) {
		int x, y;
		input(x, y);

		e.push_back({{x, -y}, i});
		a.insert(y);
	}
	sort(e.begin(), e.end());

	vector<bool> res1(n), res2(n);
	multiset<int> b;
	for (pair<pair<int, int>, int> p : e) {
		int x, y, i = p.second;
		tie(x, y) = p.first;
		y = -y;
		a.erase(a.find(y));
		res1[i] = a.upper_bound(y) != a.begin();
		res2[i] = b.lower_bound(y) != b.end();
		// print(x, y);
		b.insert(y);
	}
	
	arrPrint(res1);
	arrPrint(res2);
}

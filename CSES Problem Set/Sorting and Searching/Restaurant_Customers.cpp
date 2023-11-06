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

	vector<pair<int, bool>> v;
	range(i, 0, n) {
		int a, b;
		input(a, b);

		v.push_back({a, false});
		v.push_back({b, true});
	}
	sort(v.begin(), v.end());

	int c = 0;
	int res = 0;
	for (pair<int, bool> p : v) {
		if (p.second) {
			c--;
		}
		else {
			c++;
		}
		res = max(res, c);
	}
	print(res);
}

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

	vector<int> a(n);
	arrPut(a);

	int c = 0;
	map<int, int> m;
	m[0] = 1;

	int res = 0;
	range(i, 0, n) {
		c += a[i];
		int y = ((c % n) + n) % n;
		if (m.count(y)) {
			res += m[y];
		}
		m[y]++;
	}

	print(res);
}

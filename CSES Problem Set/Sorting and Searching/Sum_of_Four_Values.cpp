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

	int n, x;
	input(n, x);

	if (n == 1) {
		print("IMPOSSIBLE");
		return 0;
	}

	vector<int> a(n);
	arrPut(a);

	map<int, pair<int, int>> m;
	m[a[0] + a[1]] = {0, 1};
	range(i, 2, n) {
		range(j, i + 1, n) {
			int y = x - a[i] - a[j];
			if (m.count(y)) {
				print(m[y].first + 1, m[y].second + 1, i + 1, j + 1);
				return 0;
			}
		}
		range(j, 0, i) {
			m[a[j] + a[i]] = {j, i};
		}
	}

	print("IMPOSSIBLE");
}

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

	vector<int> a(n);
	arrPut(a);

	map<int, vector<int>> m;
	range(i, 0, n) {
		m[a[i]].push_back(i + 1);
	}

	for (pair<int, vector<int>> p : m) {
		if (p.first > x / 2 or (x % 2 == 0 and p.first == x / 2)) {
			break;
		}

		if (m.count(x - p.first)) {
			print(m[p.first][0], m[x - p.first][0]);
			return 0;
		}
	}

	if (x % 2 == 0 and m.count(x / 2) and m[x / 2].size() >= 2) {
		print(m[x / 2][0], m[x / 2][1]);
		return 0;
	}

	print("IMPOSSIBLE");
}

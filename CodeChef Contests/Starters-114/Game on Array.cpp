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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int s = 0;
		range(i, 0, n) {
			s += a[i];
		}
		if (s % 2 == 1) {
			print("Bob");
			continue;
		}

		int x = 0, y = 0;
		for (int i = 0; i < n; i += 2) {
			x += a[i];
		}
		for (int i = 1; i < n; i += 2) {
			y += a[i];
		}

		if (abs(x - y) % 4 == 0) {
			print("Bob");
		}
		else {
			print("Alice");
		}
	}
}

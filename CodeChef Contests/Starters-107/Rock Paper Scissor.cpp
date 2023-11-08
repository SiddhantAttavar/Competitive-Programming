#include <bits/stdc++.h>
#include <string>
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
	set<string> s = {"RS", "SP", "PR"};
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string a, b;
		input(a, b);

		int x = 0;
		range(i, 0, n) {
			string p; p += a[i]; p += b[i];
			string q; q += b[i]; q += a[i];
			x += s.count(p) - s.count(q);
		}

		// print(x);
		if (x > 0) {
			print(0);
		}
		else {
			print(-x / 2 + 1);
		}
	}
}

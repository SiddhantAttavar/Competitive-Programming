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

		vector<int> b(n);
		arrPut(b);

		bool flag = true;
		range(i, 2, n) {
			if (b[i] != b[i - 1] + b[i - 2]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			print(-1);
			continue;
		}

		int x = b[0], y = b[1];
		while (x > 0 and y - x > 0) {
			int t = x;
			x = y - x;
			y = t;
		}
		print(x, y);
	}
}

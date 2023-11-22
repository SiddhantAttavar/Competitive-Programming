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
		int n, x, y;
		input(n, x, y);

		vector<int> a(n);
		arrPut(a);

		map<int, int> m = {{a[0], 1}};
		int res = x == 1 and a[0] == y, l = 0;
		range(i, 1, n) {
			m[a[i]]++;

			while ((int) m.size() > x) {
				m[a[l]]--;
				if (m[a[l]] == 0) {
					m.erase(a[l]);
				}
				l++;
			}

			if ((int) m.size() == x and m.count(y)) {
				res = max(res, i - l + 1);
			}
		}

		print(res);
	}
}

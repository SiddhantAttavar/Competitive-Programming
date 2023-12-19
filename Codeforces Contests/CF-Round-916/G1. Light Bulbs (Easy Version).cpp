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
	int MOD = 998244353;
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(2 * n);
		arrPut(a);

		set<int> s;
		int c = 0;
		int x = 0, y = 1;
		vector<int> l(n), r(n);
		range(i, 0, 2 * n) {
			if (s.count(a[i])) {
				r[a[i] - 1] = i;
				s.erase(a[i]);
			}
			else {
				l[a[i] - 1] = i;
				s.insert(a[i]);
			}

			if (s.empty()) {
				x++;
				if (a[c] != a[i]) {
					// if (r[a[c] - 1] > l[a[i] - 1]) {
						y = (y * 2) % MOD;
					// }
				}
				y = (y * 2) % MOD;
				c = i + 1;
			}
		}
		print(x, y);
	}
}

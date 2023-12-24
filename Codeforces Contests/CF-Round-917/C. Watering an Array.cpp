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
		int n, k, d;
		input(n, k, d);

		vector<int> a(n);
		arrPut(a);

		vector<int> b(k);
		arrPut(b);

		int res = (d - 1) / 2;
		range(j, 0, n) {
			res += a[j] == j + 1;
		}

		range(i, 0, min(2 * n + 5, d - 1)) {
			range(j, 0, b[i % k]) {
				a[j]++;
			}
			int c = 0;
			range(j, 0, n) {
				c += a[j] == j + 1;
			}
			c += (d - (i + 2)) / 2;
			res = max(res, c);
		}

		print(res);
	}
}

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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		int s = 0;
		range(i, 0, n - 40) {
			s += a[i];
		}

		int u = a[n - 1], x = s;
		range(j, max(0ll, n - 40), n) {
			if (x >= a[j]) {
				u = max(u, x + a[n - 1] - a[j]);
			}
			x += a[j];
		}

		print(u);

		while (q--) {
			int i, y;
			input(i, y);

			i--;

			if (i < (n - 40)) {
				s -= a[i];
				a[i] = y;
				s += a[i];
			}
			else {
				a[i] = y;
			}

			u = a[n - 1];
			x = s;
			range(j, max(0ll, n - 40), n) {
				if (x > a[j]) {
					u = max(u, x + a[n - 1] - a[j]);
				}
				x += a[j];
			}

			print(u);
		}
	}
}

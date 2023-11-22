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

		vector<int> x(n);
		arrPut(x);

		range(i, 1, n) {
			x[i] += x[i - 1];
		}
		range(i, 0, n) {
			x[i] = abs(x[i]);
		}

		vector<int> a(n), b(n);
		a[0] = x[0];
		b[n - 1] = x[n - 1];
		range(i, 1, n) {
			a[i] = max(a[i - 1], x[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			b[i] = max(b[i + 1], x[i]);
		}
		reverse(b.begin(), b.end());

		int m;
		input(m);
		while (m--) {
			int w = 0;
			input(w);

			int i = lower_bound(a.begin(), a.end(), w) - a.begin() + 1;
			int j = n - (lower_bound(b.begin(), b.end(), w) - b.begin());

			if (i == n + 1) {
				print(-1);
			}
			else {
				print(i, j);
			}
		}
	}
}

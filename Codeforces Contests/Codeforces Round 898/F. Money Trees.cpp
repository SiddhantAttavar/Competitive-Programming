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

bool check(int m, int n, int k, vector<int> &a, vector<int> &h) {
	int x = a[m - 1], l = m - 1;
	for (int i = m - 2; i >= 0; i--) {
		x += a[i];
		if (l == (i + 1) and (h[i] % h[i + 1] == 0)) {
			l--;
		}
	}

	if (l == 0 and x <= k) {
		return true;
	}

	range(i, m, n) {
		if (h[i - 1] % h[i] != 0) {
			l = i;
		}
		x += a[i] - a[i - m];
		// print("debug", m, x, l);
		if (l <= (i - m + 1) and x <= k) {
			return true;
		}
	}

	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), h(n);
		arrPut(a);
		arrPut(h);

		int l = 1, r = n, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m, n, k, a, h)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}

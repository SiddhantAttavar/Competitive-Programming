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

	int n, m;
	input(n, m);

	vector<int> x(n);
	arrPut(x);

	vector<int> ind(n);
	range(i, 0, n) {
		x[i]--;
		ind[x[i]] = i;
	}

	vector<bool> v(n, false);
	int c = 0;
	range(i, 0, n) {
		c += x[i] == 0 or !v[x[i] - 1];
		v[x[i]] = true;
	}

	range(i, 0, m) {
		int a, b;
		input(a, b);
		a--;
		b--;

		if (x[a] < n - 1) {
			c += a < ind[x[a] + 1];
		}
		if (x[a] >= 0) {
			c += a > ind[x[a] - 1];
		}
		if (x[b] < n - 1 and x[b] + 1 != x[a]) {
			c += b < ind[x[b] + 1];
		}
		if (x[b] >= 0 and x[b] - 1 != x[a]) {
			c += b > ind[x[b] - 1];
		}

		swap(ind[x[a]], ind[x[b]]);
		swap(x[a], x[b]);

		if (x[a] < n - 1) {
			c -= a < ind[x[a] + 1];
		}
		if (x[a] >= 0) {
			c -= a > ind[x[a] - 1];
		}
		if (x[b] < n - 1 and x[b] + 1 != x[a]) {
			c -= b < ind[x[b] + 1];
		}
		if (x[b] >= 0 and x[b] - 1 != x[a]) {
			c -= b > ind[x[b] - 1];
		}

		print(c);
	}
}

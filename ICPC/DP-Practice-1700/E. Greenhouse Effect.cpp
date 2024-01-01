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

	vector<int> a(n);
	range(i, 0, n) {
		float x;
		input(a[i], x);
	}

	vector<int> c(m);
	for (int i : a) {
		c[i - 1]++;
	}

	vector<int> p(m), s(m);
	p[0] = 1;
	range(i, 1, m) {
		if (a[i] == a[i - 1]) {
			p[i] = p[i - 1] + 1;
		}
		else {
			p[i] = 1;
		}
	}
	s[m - 1] = 1;
	for (int i = m - 2; i >= 0; i--) {
		if (a[i] == a[i + 1]) {
			s[i] = s[i + 1] + 1;
		}
		else {
			s[i] = 1;
		}
	}

	vector<int> f(m + 1, 0), g(m + 1, 0);
	fill(f.begin() + 1, f.end(), 1e9);
	range(j, 1, m + 1) {
		g[j] = c[j - 1] + g[j - 1];
	}
	range(i, 1, n + 1) {
		range(j, 1, m + 1) {
			f[j] = g[j];
			if (a[i - 1] == j) {
				f[j] = min(f[j], g[j] - 1);
			}
			g[j] = min(f[j], g[j - 1] + c[j - 1]);
		}
	}

	// range(i, 0, n + 1) {
	// 	arrPrint(f[i]);
	// }
	// print("");
	// range(i, 0, n + 1) {
	// 	arrPrint(g[i]);
	// }

	print(g[m]);
}

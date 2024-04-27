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

	int N = 1e6;
	vector<int> spf(N + 1);
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] == i) {
			for (int j = i; j <= N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> b(a.begin(), a.end());

	vector<vector<int>> d(n, {1});
	range(i, 0, n) {
		map<int, int> m;
		while (a[i] != 1) {
			m[spf[a[i]]]++;
			a[i] /= spf[a[i]];
		}

		for (pair<int, int> p : m) {
			vector<int> l(d[i].begin(), d[i].end());
			int x = 1;
			range(j, 0, p.second) {
				x *= p.first;
				for (int k : d[i]) {
					l.push_back(x * k);
				}
			}
			d[i] = l;
		}
	}

	vector<int> v(N + 1, 0);
	int res = 0;
	range(i, 0, n) {
		for (int j : d[i]) {
			v[j]++;
			if (v[j] >= 2) {
				res = max(res, j);
			}
		}
	}
	print(res);
}

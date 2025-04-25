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

int n;
long long m;
int a[(int) 2e5 + 5], d[(int) 2e5 + 5];

bool check() {
	int b[n];
	copy(a, a + n, b);

	vector<int> v[n];
	fill(v, v + n, vector<int>());
	range(i, 0, n) {
		if (b[i]) {
			v[max(0, i - d[i])].push_back(i);
		}
	}

	int l[n];
	fill(l, l + n, 0);

	set<pair<int, int>> s;
	range(i, 0, n) {
		for (int j : v[i]) {
			s.insert({min(n - 1, j + d[j]), j});
		}

		while (!s.empty() and l[i] != m) {
			int r, j;
			tie(r, j) = *s.begin();

			if (r < i) {
				return false;
			}

			if (b[j] + l[i] <= m) {
				l[i] += b[j];
				b[j] = 0;
				s.erase(s.begin());
			}
			else {
				b[j] -= m - l[i];
				l[i] = (int) m;
			}
		}
	}

	return s.empty();
}

int32_t main() {
	setup();

	input(n);

	range(i, 0, n) {
		input(a[i]);
	}
	range(i, 0, n) {
		input(d[i]);
	}

	int l = 0, r = 1e9, res = -1;
	while (l <= r) {
		m = (l + r) / 2;
		if (check()) {
			res = (int) m;
			r = (int) m - 1;
		}
		else {
			l = (int) m + 1;
		}
	}
	
	print(res);
}

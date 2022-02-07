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

	int n;
	cin >> n;

	vector<tuple<int, int, int>> v(n);
	range(i, 0, n) {
		int x, y, z;
		input(x, y, z);
		v[i] = {x, y, z};
	}

	set<int> sx, sy;
	for (tuple<int, int, int> t : v) {
		int x, y, z;
		tie(x, y, z) = t;
		sx.insert(x);
		sy.insert(y);
	}

	vector<int> x(sx.begin(), sx.end());
	vector<int> y(sy.begin(), sy.end());

	vector<vector<int>> a(x.size(), vector<int>(y.size()));
	for (tuple<int, int, int> t : v) {
		int u, v, w;
		tie(u, v, w) = t;
		int i = lower_bound(x.begin(), x.end(), u) - x.begin();
		int j = lower_bound(y.begin(), y.end(), v) - y.begin();
		a[i][j] += w;
	}

	vector<vector<int>> p(x.size() + 1, vector<int>(y.size() + 1));
	range(i, 0, x.size()) {
		range(j, 0, y.size()) {
			p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + a[i][j];
		}
	}

	vector<int> z;
	for (int i : x) {
		z.push_back(i);
	}
	for (int i : y) {
		z.push_back(i);
	}
	sort(z.begin(), z.end());

	int res = 0;
	range(u, 0, z.size()) {
		range(v, u, z.size()) {
			int x1 = lower_bound(x.begin(), x.end(), z[u]) - x.begin();
			int y1 = lower_bound(y.begin(), y.end(), z[u]) - y.begin();
			int x2 = upper_bound(x.begin(), x.end(), z[v]) - x.begin();
			int y2 = upper_bound(y.begin(), y.end(), z[v]) - y.begin();
			// print(z[u], z[v], x1, x2, y1, y2, p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1]);
			res = max(res, p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1]);
		}
	}
	print(res);
}

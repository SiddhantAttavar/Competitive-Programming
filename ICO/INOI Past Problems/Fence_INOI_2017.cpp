#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int r, c, n;
set<pair<int, int>> v, a;

long long dfs(int x, int y) {
	v.insert({x, y});
	long long res = 4;
	if (a.find({x - 1, y}) != a.end()) {
		res--;
		if (v.find({x - 1, y}) == v.end()) {
			res += dfs(x - 1, y);
		}
	}
	if (a.find({x + 1, y}) != a.end()) {
		res--;
		if (v.find({x + 1, y}) == v.end()) {
			res += dfs(x + 1, y);
		}
	}
	if (a.find({x, y - 1}) != a.end()) {
		res--;
		if (v.find({x, y - 1}) == v.end()) {
			res += dfs(x, y - 1);
		}
	}
	if (a.find({x, y + 1}) != a.end()) {
		res--;
		if (v.find({x, y + 1}) == v.end()) {
			res += dfs(x, y + 1);
		}
	}
	return res;
}

int main() {
	setup();
	cin >> r >> c >> n;

	range(i, 0, n) {
		input(int, x);
		input(int, y);
		a.insert({x, y});
	}

	long long res = 0;
	for (pair<int, int> p : a) {
		if (v.find(p) == v.end()) {
			res = max(res, dfs(p.first, p.second));
		}
	}

	print(res);
}
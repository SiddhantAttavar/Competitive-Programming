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

bool check(double m, vector<pair<pair<int,int>, double>> &a, int x, int y) {
	double p = 0;
	int q = 0;
	for (pair<pair<int, int>, double> i : a) {
		int l, u;
		tie(l, u) = i.first;
		double w = i.second;

		p += m * (double) (l - q);
		q = l;

		p += m * w * (double) (u - q);
		q = u;
	}
	p += m * (double) (y - q);

	return p >= (double) x;
}

int32_t main() {
	setup();

	int x, y;
	input(x, y);

	int n;
	input(n);

	vector<pair<pair<int, int>, double>> a(n);
	range(i, 0, n) {
		input(a[i].first.first, a[i].first.second);
		input(a[i].second);
	}

	double l = -1e9, r = 1e9, res;
	while ((r - l) > (1e-9)) {
		double m = (l + r) / 2;
		if (check(m, a, x, y)) {
			res = m;
			r = m;
		}
		else {
			l = m;
		}
	}

	cout.precision(20);
	print(res);
}

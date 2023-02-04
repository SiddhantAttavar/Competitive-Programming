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

vector<int> a, p, u;

int get(int x) {
	if (u[x] <= 0) {
		return x;
	}
	return u[x] = get(u[x]);
}

void unite(int x, int y) {
	x = get(x);
	y = get(y);

	if (x == y) {
		return;
	}

	if (u[x] < u[y]) {
		swap(x, y);
	}

	u[y] += u[x];
	u[x] = y;
}

int32_t main() {
	setup();

	int n;
	input(n);

	a.resize(n);
	arrPut(a);

	p.resize(n);
	arrPut(p);
	reverse(p.begin(), p.end());

	u.resize(n + 1);
	range(i, 1, n + 1) {
		u[i] = -a[i - 1];
	}

	int m = 0;
	vector<int> res;
	set<int> s;
	for (int i : p) {
		res.push_back(m);
		if (i > 1 and s.count(i - 1)) {
			unite(i, i - 1);
		}
		if (i < n and s.count(i + 1)) {
			unite(i, i + 1);
		}
		m = max(m, -u[get(i)]);
		s.insert(i);
	}
	reverse(res.begin(), res.end());

	// cout << res.size() << endl;
	// cout << p.size() << endl;

	for (int i : res) {
		print(i);
	}
}

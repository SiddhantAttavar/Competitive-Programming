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

int n, m, p;
vector<vector<int>> graph;

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = get(a[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return false;
		}

		if (a[x] < a[y]) {
			swap(x, y);
		}

		a[y] += a[x];
		a[x] = y;
		return true;
	}
};

int32_t main() {
	setup();

	input(n, m, p);

	graph.clear();
	graph.resize(n);
	vector<pair<int, int>> e(m);
	range(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
		e[i] = {u - 1, v - 1};
		if (e[i].first > e[i].second) {
			swap(e[i].first, e[i].second);
		}
	}

	vector<string> res;
	range(i, 0, m) {
		DSU d(n);
		int c = n;
		range(j, 0, m) {
			if (i != j) {
				if (d.unite(e[j].first, e[j].second)) {
					c--;
				}
			}
		}

		if (c == 2) {
			string s;
			range(j, 0, n) {
				s += '0' + (d.get(j) != d.get(0));
			}
			res.push_back(s);
		}
	}

	print(res.size());
	for (string s : res) {
		print(s);
	}
}


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

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.clear();
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

		if (a[x] > a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;

		return true;
	}

	int size(int x) {
		return -a[get(x)];
	}
};

vector<int> l;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		l.clear();
		l.resize(n);
		arrPut(l);

		DSU d(n);
		vector<pair<int, int>> edges;
		range(i, 0, m) {
			int u, v;
			input(u, v);

			edges.push_back({u - 1, v - 1});
		}
		sort(edges.begin(), edges.end(), [](pair<int, int> &a, pair<int, int> &b) {
			return min(l[a.first], l[a.second]) > min(l[b.first], l[b.second]);
		});

		int x = -1;
		for (pair<int, int> p : edges) {
			d.unite(p.first, p.second);

			if (d.size(p.first) >= k) {
				x = d.get(p.first);
				break;
			}
		}

		if (x == -1) {
			print(-1);
			continue;
		}

		int res = 1e10;
		range(i, 0, n) {
			if (d.get(i) == x) {
				res = min(res, l[i]);
			}
		}

		print(res);
	}
}

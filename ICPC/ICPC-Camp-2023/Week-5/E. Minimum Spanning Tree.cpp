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
		a.resize(n, -1);
	}

	int get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = get(a[x]);
	}

	bool unite(int x, int y) {
		// print(x, y);
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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<pair<pair<int, int>, pair<int, int>>> e(n - 1);
		vector<vector<pair<pair<int, int>, pair<int, int>>>> graph(n);
		range(i, 0, n - 1) {
			input(e[i].first.first, e[i].first.second, e[i].second.first);
			e[i].first.first--;
			e[i].first.second--;
			e[i].second.second = i;
			graph[e[i].first.first].push_back(e[i]);
			graph[e[i].first.second].push_back(e[i]);
		}
		sort(e.begin(), e.end(), [](pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
			return a.second.first < b.second.first;
		});
		// range(i, 0, n - 1) {
		// 	print(e[i].second.second);
		// }

		int res = 0;
		DSU d(n - 1);
		vector<bool> s(n, false);
		for (pair<pair<int, int>, pair<int, int>> p : e) {
			int u, v;
			tie(u, v) = p.first;

			if (!s[u]) {
				sort(graph[u].begin(), graph[u].end(), [](pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
					return a.second.first < b.second.first;
				});

				range(i, 1, (int) graph[u].size()) {
					range(j, 0, i) {
						if (d.unite(graph[u][j].second.second, graph[u][i].second.second)) {
							res += graph[u][j].second.first + graph[u][i].second.first;
							break;
						}
					}
				}

				s[u] = true;
			}

			if (!s[v]) {
				sort(graph[v].begin(), graph[v].end(), [](pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
					return a.second.first < b.second.first;
				});

				range(i, 1, (int) graph[v].size()) {
					range(j, 0, i) {
						if (d.unite(graph[v][j].second.second, graph[v][i].second.second)) {
							res += graph[v][j].second.first + graph[v][i].second.first;
							break;
						}
					}
				}

				s[v] = true;
			}
		}

		print(res);
	}
}

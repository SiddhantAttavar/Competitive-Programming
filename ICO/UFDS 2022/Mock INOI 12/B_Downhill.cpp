#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

void dfs(vector<tuple<int, int, int, int>> &c, vector<bool> &visited, vector<int> &topo, int u, int n) {
	visited[u] = true;
	int x1, y1, s1, e1;
	tie(x1, y1, s1, e1) = c[u];
	range(v, u + 1, n) {
		int x2, y2, s2, e2;
		tie(x2, y2, s2, e2) = c[v];
		
		if (y1 - y2 > e1) {
			break;
		}
		if (abs(x2 - x1) > e1) {
			continue;
		}

		if (!visited[v]) {
			dfs(c, visited, topo, v, n);
		}
	}
	topo.push_back(u);
}

int32_t main() {
	setup();
	
	int n, h;
	input(n, h);
	vector<tuple<int, int, int, int>> c(n);
	range(i, 0, n) {
		int x, y, s, e;
		input(x, y, s, e);
		c[i] = {x, y, s, e};
	}
	sort(c.begin(), c.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
		return get<1>(a) > get<1>(b);
	});
	
	vector<bool> visited(n);
	vector<vector<int>> topo;
	range(i, 0, n) {
		if (!visited[i]) {
			topo.push_back({});
			dfs(c, visited, topo.back(), i, n);
			reverse(topo.back().begin(), topo.back().end());
		}
	}

	vector<int> dist(n);
	range(i, 0, n) {
		dist[i] = get<2>(c[i]);
	}
	for (vector<int> t : topo) {
		for (int u : t) {
			int x1, y1, s1, e1;
			tie(x1, y1, s1, e1) = c[u];
			range(v, u + 1, n) {
				int x2, y2, s2, e2;
				tie(x2, y2, s2, e2) = c[v];
				
				if (y1 - y2 > e1) {
					break;
				}
				if (abs(x2 - x1) > e1) {
					continue;
				}

				dist[v] = max(dist[v], dist[u] + get<2>(c[v]));
			}
		}
	}
	print(*max_element(dist.begin(), dist.end()));
}

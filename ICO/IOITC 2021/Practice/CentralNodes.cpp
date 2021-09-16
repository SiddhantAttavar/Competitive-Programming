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
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int n, m; input(n, m);
	vector<pair<int, int>> graph[n];
	while (m--) {
		int u, v, w; input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	int central[n] = {0};
	ll dist[n][n];
	int curr[n][n];
	range(i, 0, n) {
		fill(curr[i], curr[i] + n, -1);
		fill(dist[i], dist[i] + n, 1e15);
		dist[i][i] = 0;
		for (pair<int, int> p : graph[i]) {
			dist[i][p.first] = p.second;
		}
	}

	range(k, 0, n) {
		range(i, 0, n) {
			range(j, i + 1, n) {
				if (k == i || k == j) {
					continue;
				}
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					central[k]++;
					if (curr[i][j] != -1) {
						central[curr[i][j]]--;
					}
					curr[i][j] = k;
				}
				else if (dist[i][k] + dist[k][j] == dist[i][j]) {
					if (curr[i][j] != -1) {
						central[curr[i][j]]--;
						curr[i][j] = -1;
					}
				}
			}
		}
	}

	vector<int> res;
	range(i, 0, n) {
		if (central[i] > 0) {
			res.push_back(i + 1);
		}
	}
	print(res.size());
	arrPrint(res);
}
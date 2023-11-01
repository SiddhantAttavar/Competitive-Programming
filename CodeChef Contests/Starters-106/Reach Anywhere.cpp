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

int MAXX = (int) 1e5 + 5;
int INF = 1e16;
 
// returns value which will
// represent even_x
int even(int x) {
    return x * 2 + 2;
}
// returns value which will
// represent odd_x
int odd(int x) {
    return x * 2 + 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(2 * n + 1);
		vector<int> dist(2 * n + 1, INF);
		range(i, 0, m) {
			int u, v;
			input(u, v);

			graph[even(u - 1)].push_back(odd(v - 1));
			graph[odd(v - 1)].push_back(even(u - 1));

			graph[odd(u - 1)].push_back(even(v - 1));
			graph[even(v - 1)].push_back(odd(u - 1));
		}

		queue<int> q;
		q.push(1);
		dist[1] = 0;
	 
		while (!q.empty()) {
			int u = q.front();
			q.pop();
	 
			for (int v : graph[u]) {
				if (dist[u] + 1 < dist[v]) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		int res1 = 0, res2 = 1;
		range(i, 0, n) {
			res1 = max(res1, dist[even(i)]);
			res2 = max(res2, dist[odd(i)]);
		}

		if (min(res1, res2) == INF) {
			print(-1);
		}
		else {
			print(min(res1, res2));
		}
	}
}

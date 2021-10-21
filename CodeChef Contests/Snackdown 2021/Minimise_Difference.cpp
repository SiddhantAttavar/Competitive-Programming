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

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m; input(n, m);
		vector<int> graph[n];
		int deg[n];
		range(i, 0, n) {
			deg[i] = 0;
		}
		range(i, 0, m) {
			int u, v; input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
			deg[u - 1]++;
			deg[v - 1]++;
		}

		int c[n], d[n];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		range(i, 0, n) {
			pq.push({deg[i], i});
		}

		range(i, 0, n) {
			c[i] = pq.top().second;
			pq.pop();
			i++;
			pq.push({deg[i], i});

		}

		while (!pq.empty()) {
			
		}

		print(*max_element(d, d + n));
		arrPrint(c);
	}
}
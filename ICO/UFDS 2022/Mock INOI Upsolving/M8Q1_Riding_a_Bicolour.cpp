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

int32_t main() {
	setup(); 
	int s; input(s);
	int n, m, q; input(n, m, q);
	
	vector<vector<int>> a(n, vector<int>(m));
	range(i, 0, n) {
		arrPut(a[i]);
	}

	vector<vector<int>> color(n, vector<int>(m, -1));

	int curr = 0;
	range(i, 0, n) {
		range(j, 0, m) {
			if (color[i][j] == -1) {
				color[i][j] = curr;
				queue<pair<int, int>> q;
				q.push({i, j});
				while (!q.empty()) {
					int u, v;
					tie(u, v) = q.front();
					q.pop();

					if (u - 1 >= 0 && a[u - 1][v] != a[u][v] && color[u - 1][v] == -1) {
						color[u - 1][v] = curr;
						q.push({u - 1, v});
					}
					if (u + 1 < n && a[u + 1][v] != a[u][v] && color[u + 1][v] == -1) {
						color[u + 1][v] = curr;
						q.push({u + 1, v});
					}
					if (v - 1 >= 0 && a[u][v - 1] != a[u][v] && color[u][v - 1] == -1) {
						color[u][v - 1] = curr;
						q.push({u, v - 1});
					}
					if (v + 1 < m && a[u][v + 1] != a[u][v] && color[u][v + 1] == -1) {
						color[u][v + 1] = curr;
						q.push({u, v + 1});
					}
				}
				curr++;
			}
		}
	}

	while (q--) {
		int a, b, x, y; input(a, b, x, y);
		print(color[a - 1][b - 1] == color[x - 1][y - 1]);
	}
}
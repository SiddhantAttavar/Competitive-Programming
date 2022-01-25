// https://codebreaker.xyz/problem/milkweed
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
	
	int n, m, a, b;
	input(n, m, a, b);
	swap(n, m);
	swap(a, b);
	vector<vector<bool>> grid(n, vector<bool>(m));
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			grid[i][j] = s[j] == '.';
		}
	}
	
	vector<vector<bool>> visited(n, vector<bool>(m));
	queue<pair<pair<int, int>, int>> q;
	int res = 0;
	q.push({{n - a, b - 1}, 0});
	visited[n - a][b - 1] = true;
	while (!q.empty()) {
		int x, y, d = q.front().second;
		tie(x, y) = q.front().first;
		q.pop();

		res = d;
		vector<pair<int, int>> neighbours = {
			{x - 1, y - 1},
			{x, y - 1},
			{x + 1, y - 1},
			{x - 1, y},
			{x + 1, y},
			{x - 1, y + 1},
			{x, y + 1},
			{x + 1, y + 1}
		};
		for (pair<int, int> p : neighbours) {
			int u, v;
			tie(u, v) = p;
			if (u < 0 or u >= n or v < 0 or v >= m) {
				continue;
			}
			if (!visited[u][v] and grid[u][v]) {
				visited[u][v] = true;
				q.push({{u, v}, d + 1});
			}
		}
	}

	print(res);
}

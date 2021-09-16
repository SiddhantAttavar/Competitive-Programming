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

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '0') {
		return 0;
	}
	visited[i][j] = true;
	return dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1) + 1;
}

int main() {
	setup(); int tc; input(tc); while (tc--) {
		input(n, m);
		grid.resize(n);
		arrPut(grid);
		visited.clear();
		visited = vector<vector<bool>>(n, vector<bool>(m, false));

		vector<int> compSize;
		range(i, 0, n) {
			range(j, 0, m) {
				if (!visited[i][j]) {
					compSize.push_back(dfs(i, j));
				}
			}
		}
		sort(compSize.begin(), compSize.end());
		reverse(compSize.begin(), compSize.end());

		int p1 = 0, p2 = 0;
		range(i, 0, compSize.size()) {
			p1 += compSize[i];
			if (++i < compSize.size()) {
				p2 += compSize[i];
			}
		}

		print(p2);
	}
}
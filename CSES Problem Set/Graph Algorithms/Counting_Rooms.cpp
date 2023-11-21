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

void dfs(int x, int y, int n, int m, vector<vector<bool>> &v) {
	v[x][y] = true;
	vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (pair<int, int> p : d) {
		int i = x + p.first, j = y + p.second;
		if (i >= 0 and i < n and j >= 0 and j < m and !v[i][j]) {
			dfs(i, j, n, m, v);
		}
	}
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<bool>> v(n, vector<bool>(m));
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			v[i][j] = s[j] == '#';
		}
	}

	int c = 0;
	range(i, 0, n) {
		range(j, 0, m) {
			if (!v[i][j]) {
				dfs(i, j, n, m, v);
				c++;
			}
		}
	}

	print(c);
}

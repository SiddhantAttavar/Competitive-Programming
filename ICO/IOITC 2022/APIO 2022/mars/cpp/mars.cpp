#include "mars.h"
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void dfs(int i, int j, int n, vector<vector<bool>> &a, vector<vector<bool>> &visited) {
	// print(i, j);
	if (i < 0 or i > 2 * n or j < 0 or j > 2 * n) {
		return;
	}

	if (!a[i][j] or visited[i][j]) {
		return;
	}

	visited[i][j] = true;
	
	dfs(i - 1, j, n, a, visited);
	dfs(i + 1, j, n, a, visited);
	dfs(i, j - 1, n, a, visited);
	dfs(i, j + 1, n, a, visited);
}

vector<vector<bool>> decode(string s, int n) {
	vector<vector<bool>> a(2 * n + 1, vector<bool>(2 * n + 1));
	range(i, 0, 2 * n + 1) {
		range(j, 0, 2 * n + 1) {
			a[i][j] = s[i * (2 * n + 1) + j] == '1';
		}
	}
	return a;
}

string encode(vector<vector<bool>> &a, int n, int x, int y) {
	// for (auto x : a) {
	// 	arrPrint(x);
	// }
	string res;
	range(i, 0, 2 * n + 1) {
		range(j, 0, 2 * n + 1) {
			res += '0' + a[i][j];
			// print('0' + a[i][j]);
		}
	}
	if (res.size() < 100) {
		res = res + string(100 - res.size(), '0');
	}
	res[0] = '0' + a[x][y];
	// print(res);
	return res;
}

string findIslands(vector<vector<bool>> &a, int n) {
	// for (auto x : a) {
	// 	arrPrint(x);
	// }
	vector<vector<bool>> visited(2 * n + 1, vector<bool>(2 * n + 1, false));
	
	int c = 0;
	range(i, 0, 2 * n + 1) {
		range(j, 0, 2 * n + 1) {
			if (a[i][j] and !visited[i][j]) {
				// print(i, j);
				dfs(i, j, n, a, visited);
				c++;
			}
		}
	}
	
	string res;
	range(i, 0, 100) {
		if (c & 1) {
			res += '1';
		}
		else {
			res += '0';
		}
		
		c >>= 1;
	}
	
	return res;
}

string process(vector<vector<string>> a, int i, int j, int k, int n) {
	vector<vector<bool>> res(2 * n + 1, vector<bool>(2 * n + 1, false));
	
	range(x, i, i + 3) {
		range(y, j, j + 3) {
			vector<vector<bool>> v = decode(a[x - i][y - j], n);
			range(p, 0, 2 * n + 1) {
				range(q, 0, 2 * n + 1) {
					if (p != 0 or q != 0) {
						res[p][q] = res[p][q] or v[p][q];
					}
				}
			}
			// print(x, y, i, j);
			res[x][y] = a[x - i][y - j][0] == '1';
		}
	}

	// for (auto x : res) {
	// 	arrPrint(x);
	// }
	
	// for (auto x : decode(encode(res, n, i, j), n)) {
	// 	arrPrint(x);
	// }
	// print("");

	if (k == n - 1) {
		return findIslands(res, n);
	}

	return encode(res, n, i, j);
}

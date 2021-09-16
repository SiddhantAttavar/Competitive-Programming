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

int n, m, k;
vector<vector<int>> grid;

bool squarePossible(int i, int j) {
	int sum = grid[i][j] + grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1];

	if (sum == 1 || sum == 3) {
		grid[i][j] = grid[i][j] == -1 ? 0 : grid[i][j];
		grid[i + 1][j] = grid[i + 1][j] == -1 ? 0 : grid[i + 1][j];
		grid[i][j + 1] = grid[i][j + 1] == -1 ? 0 : grid[i][j + 1];
		grid[i + 1][j + 1] = grid[i + 1][j + 1] == -1 ? 0 : grid[i + 1][j + 1];
		return true;
	}
	
	if (grid[i][j] == -1) {
		grid[i][j] = 1;
		grid[i + 1][j] = grid[i + 1][j] == -1 ? 0 : grid[i + 1][j];
		grid[i][j + 1] = grid[i][j + 1] == -1 ? 0 : grid[i][j + 1];
		grid[i + 1][j + 1] = grid[i + 1][j + 1] == -1 ? 0 : grid[i + 1][j + 1];
		return true;
	}
	else if (grid[i + 1][j] == -1) {
		grid[i + 1][j] = 1;
		grid[i][j + 1] = grid[i][j + 1] == -1 ? 0 : grid[i][j + 1];
		grid[i + 1][j + 1] = grid[i + 1][j + 1] == -1 ? 0 : grid[i + 1][j + 1];
		return true;
	}
	else if (grid[i][j + 1] == -1) {
		grid[i][j + 1] = 1;
		grid[i + 1][j + 1] = grid[i + 1][j + 1] == -1 ? 0 : grid[i + 1][j + 1];
		return true;
	}
	else if (grid[i + 1][j + 1] == -1) {
		grid[i + 1][j + 1] = 1;
		return true;
	}

	return false;
}

bool isPossible(int i, int j) {
	if (i > 0 && j > 0 && !squarePossible(i - 1, j - 1)) {
		return false;
	}

	if (i > 0 && j < n - 1 && !squarePossible(i - 1, j)) {
		return false;
	}

	if (i < n - 1 && j > 0 && !squarePossible(i, j - 1)) {
		return false;
	}

	if (i < n - 1 && j < n - 1 && !squarePossible(i, j)) {
		return false;
	}

	return true;
}

int main() {
	setup();
	input(n, m, k);

	grid = vector<vector<int>>(n, vector<int>(m, -1));
	while (k--) {
		int x, y, c; input(x, y, c);
		grid[x - 1][y - 1] = c;
	}

	int res = 1;
	range(i, 0, n) {
		range(j, 0, n) {
			if (grid[i][j] != -1) {
				continue;
			}

			int curr[3][3];
			range(k, 0, 3) {
				range(l, 0, 3) {
					int x = i + k - 1, y = j + l - 1;
					if (x >= 0 && x < n && y >= 0 && y < m) {
						curr[k][l] = grid[x][y];
					}
				}
			}

			//First check if grid[i][j] = 1 is possible
			grid[i][j] = 1;
			if (isPossible(i, j)) {
				range(k, 0, 3) {
					range(l, 0, 3) {
						int x = i + k - 1, y = j + l - 1;
						if (x >= 0 && x < n && y >= 0 && y < m) {
							grid[x][y] = curr[k][l];
						}
					}
				}

				//Check if grid[i][j] = 0 is possible
				grid[i][j] = 0;
				if (isPossible(i, j)) {
					print(i, j);
					//Both grid[i][j] = 0 or grid[i][j] = 1 are possible
					res = (res * 2) % MOD;
				}
				else {
					//grid[i][j] is not possible
					grid[i][j] = 1;
					isPossible(i, j);
				}
			}
			else {
				range(k, 0, 3) {
					range(l, 0, 3) {
						int x = i + k - 1, y = j + l - 1;
						if (x >= 0 && x < n && y >= 0 && y < m) {
							grid[x][y] = curr[k][l];
						}
					}
				}

				//We must keep grid[i][j] = 0
				grid[i][j] = 0;
				isPossible(i, j);
			}
		}
	}

	print(res);
}
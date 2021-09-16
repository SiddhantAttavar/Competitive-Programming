#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int r, c;
bool mat[1000][1000];
int startX, startY;
int endX, endY;
vector<pair<int, int>> path;

bool solve(int i, int j) {
	if (!mat[i][j]) {
		return false;
	}
	if (i == endX && j == endY) {
		path.push_back({i, j});
		return true;
	}
	mat[i][j] = false;
	
	if (solve((i + 1) % r, j) || solve((i + r - 1) % r, j) || solve(i, (j + 1) % c) || solve(i, (j + c - 1) % c)) {
		path.push_back({i, j});
		return true;
	}
	return false;
}

int main() {
	setup();
	cin >> r >> c;
	string grid[r];
	range(i, 0, r) {
		cin >> grid[i];
		range(j, 0, c) {
			mat[i][j] = grid[i][j] != '#';
			if (grid[i][j] == 'M') {
				startX = i;
				startY = j;
			}
			else if (grid[i][j] == 'D') {
				endX = i;
				endY = j;
			}
		}
	}

	if (solve(startX, startY)) {
		print("YES");
		for (pair<int, int> p : path) {
			grid[p.first][p.second] = 'x';
		}
		grid[startX][startY] = 'M';
		grid[endX][endY] = 'D';
		for (string s : grid) {
			print(s);
		}
	}
	else {
		print("NO");
	}
}
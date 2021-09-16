#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
	setup();

	int m, n;
	cin >> m >> n;
	int grid[m + 1][n + 1] = {{0}};
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
			grid[i][j] += grid[i][j - 1];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			grid[i][j] += grid[i - 1][j];
		}
	}

	input(int, c);
	int x1, x2, y1, y2;
	while (c--) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		print(grid[x2][y2] - grid[x2][y1] - grid[x1][y2] + grid[x1][y1]);
	}
}
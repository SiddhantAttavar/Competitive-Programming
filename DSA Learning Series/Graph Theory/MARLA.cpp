#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> visited;

int dfs(int i, int j) {
	int res = 1;
	visited[i][j] = true;

	if (i > 0 && !visited[i - 1][j] && a[i][j] == a[i - 1][j]) {
		res += dfs(i - 1, j);
	}

	if (i < n - 1 && !visited[i + 1][j] && a[i][j] == a[i + 1][j]) {
		res += dfs(i + 1, j);
	}

	if (j > 0 && !visited[i][j - 1] && a[i][j] == a[i][j - 1]) {
		res += dfs(i, j - 1);
	}

	if (j < m - 1 && !visited[i][j + 1] && a[i][j] == a[i][j + 1]) {
		res += dfs(i, j + 1);
	}

	return res;
}

int main() {
	setup();
	input(n);
	input(m);

	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	a = vector<vector<int>>(n, vector<int>(m));
	range(i, 0, n) {
		arrPut(a[i]);
	}

	int maxSize = 0;
	int minStrength = INT_MAX;
	range(i, 0, n) {
		range(j, 0, m) {
			if (!visited[i][j]) {
				int size = dfs(i, j);
				if (size > maxSize) {
					maxSize = size;
					minStrength = a[i][j];
				}
				else if (size == maxSize && a[i][j] < minStrength) {
					minStrength = a[i][j];
				}
			}
		}
	}

	print(minStrength << " " << maxSize);
}
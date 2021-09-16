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

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m;
		input(n);
		input(m);

		bool grid[n][m];
		int x1 = -1, y1 = -1;
		range(i, 0, n) {
			string s; input(s);
			range(j, 0, m) {
				grid[i][j] = s[j] == '1';
				if (grid[i][j] && x1 == -1) {
					x1 = i;
					y1 = j;
				}
			}
		}

		int x2 = x1 + 1, y2 = y1 + 1;
		while (x2 < n && grid[x2][y1]) {
			x2++;
		}
		x2--;

		while (y2 < m && grid[x2][y2]) {
			y2++;
		}
		y2--;

		int sum = 0;
		bool flag = true;
		range(i, 0, n) {
			range(j, 0, m) {
				sum += grid[i][j];
				if (grid[i][j] && !(i >= x1 && i <= x2 && j >= y1 && j <= y2)) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}

		print((flag && sum == (x2 - x1 + 1) * (y2 - y1 + 1) ? "YES" : "NO"));
	}
}
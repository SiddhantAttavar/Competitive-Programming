#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, n);
	input(int, m);
	
	bool mat[n][m], visited[n][m];
	range(i, 0, n) {
		input(string, s);
		range(j, 0, m) {
			mat[i][j] = s[j] == '.';
			visited[i][j] = false;
		}
	}

	queue<pair<int, int>> q;
	int rooms = 0;
	range(i, 0, n) {
		range(j, 0, m) {
			if (mat[i][j] && !visited[i][j]) {
				rooms++;
				q.push({i, j});
				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();
					int x = p.first;
					int y = p.second;

					if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] && !visited[x][y]) {
						visited[x][y] = true;
						q.push({x - 1, y});
						q.push({x + 1, y});
						q.push({x, y - 1});
						q.push({x, y + 1});
					}
				}
			}
		}
	}

	print(rooms);
}
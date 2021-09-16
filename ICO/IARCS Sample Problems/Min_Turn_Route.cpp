#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const int INF = 1e9;

int main() {
	setup();
	
	input(int, m);
	input(int, n);

	char discs[m][n][4];
	range(i, 0, m) {
		range(j, 0, n) {
			range(k, 0, 4) {
				input(string, s);
				discs[i][j][k] = s[0];
			}
		}
	}

	int cost[m][n][4];
	range(i, 0, m) {
		range(j, 0, n) {
			int p[4][2] = {{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}};
			range(k, 0, 4) {
				if (p[k][0] >= 0 && p[k][0] < m && p[k][1] >= 0 && p[k][1] < n) {
					int index = find(discs[i][j], discs[i][j] + 4, discs[p[k][0]][p[k][1]][(k + 2) % 4]) - discs[i][j];
					cost[i][j][k] = (4 + k - index) % 4;
				}
			}
		}
	}

	//Dijkstras Algorithm
	int distance[m][n];
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	range(i, 0, m) {
		range(j, 0, n) {
			if (i == 0 && j == 0) {
				distance[0][0] = 0;
			}
			else {
				distance[i][j] = INF;
			}
			pq.push({distance[i][j], {i, j}});
		}
	}

	while (!pq.empty()) {
		int i, j;
		tie(i, j) = pq.top().second;
		pq.pop();

		if (i == (m - 1) && j == (n - 1)) {
			break;
		}

		if (i >= 0 && (distance[i][j] + cost[i][j][0]) < distance[i - 1][j]) {
			distance[i - 1][j] = distance[i][j] + cost[i][j][0];
			pq.push({distance[i - 1][j], {i - 1, j}});
		}
		if (j < n && (distance[i][j] + cost[i][j][1]) < distance[i][j + 1]) {
			distance[i][j + 1] = distance[i][j] + cost[i][j][1];
			pq.push({distance[i][j + 1], {i, j + 1}});
		}
		if (i < m && (distance[i][j] + cost[i][j][2]) < distance[i + 1][j]) {
			distance[i + 1][j] = distance[i][j] + cost[i][j][2];
			pq.push({distance[i + 1][j], {i + 1, j}});
		}
		if (j >= 0 && (distance[i][j] + cost[i][j][2]) < distance[i - 1][j]) {
			distance[i][j - 1] = distance[i][j] + cost[i][j][3];
			pq.push({distance[i][j - 1], {i, j - 1}});
		}
	}

	print(distance[m - 1][n - 1]);
}
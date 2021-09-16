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
	input(int, q);

	long long cost[n][n];
	range(i, 0, n) {
		fill(cost[i], cost[i] + n, LONG_LONG_MAX);
		cost[i][i] = 0;
	}

	range(i, 0, m) {
		input(int, a);
		input(int, b);
		input(long long, c);
		cost[a - 1][b - 1] = min(cost[a - 1][b - 1], c);
		cost[b - 1][a - 1] = min(cost[a - 1][b - 1], c);
	}

	range(k, 0, n) {
		range(i, 0, n) {
			range(j, 0, n) {
				if (cost[i][k] != LONG_LONG_MAX && cost[k][j] != LONG_LONG_MAX) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
	}

	range(i, 0, q) {
		input(int, a);
		input(int, b);
		if (cost[a - 1][b - 1] == LONG_LONG_MAX) {
			print(-1);
		}
		else {
			print(cost[a - 1][b - 1]);
		}
	}
}
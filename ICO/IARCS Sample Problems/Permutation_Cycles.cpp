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
	arrput(int, a, n);
	
	bool visited[n];
	fill(visited, visited + n, false);
	vector<vector<int>> cycles;
	range(i, 0, n) {
		if (!visited[i]) {
			vector<int> cycle;
			int x = i;
			do {
				visited[x] = true;
				cycle.push_back(x + 1);
				x = a[x] - 1;
			} while (x != i);
			cycles.push_back(cycle);
		}
	}

	print(cycles.size());
	for (vector<int> cycle : cycles) {
		for (int i : cycle) {
			cout << i << " ";
		}
		print(cycle[0]);
	}
}
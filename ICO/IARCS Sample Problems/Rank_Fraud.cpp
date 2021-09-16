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
	
	//Input
	input(int, n);
	bool graph[n][n];
	range(i, 0, n) {
		fill(graph[i], graph[i] + n, false);
		input(int, m);
		while (m--) {
			input(int, j);
			graph[i][j - 1] = true;
		}
	}

	vector<int> path = {!graph[0][1], graph[0][1]};
	range(i, 2, n) {
		int j = 0;
		for (; j < i; j++) {
			if (graph[i][path[j]]) {
				break;
			}
		}
		path.insert(path.begin() + j, i);
	}

	print("YES");
	for (int i : path) {
		cout << i + 1 << " ";
	}
}
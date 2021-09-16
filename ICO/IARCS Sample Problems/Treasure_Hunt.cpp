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
	
	input(int, m);
	input(int, t);
	input(int, s);
	input(int, n);

	pair<int, int> graph[m][t];
	range(i, 0, m) {
		range(j, 0, t) {
			cin >> graph[i][j].first >> graph[i][j].second;
			graph[i][j].first--;
			graph[i][j].second--;
		}
	}

	set<pair<int, int>> done;
	vector<pair<int, int>> passed;
	pair<int, int> curr = {s - 1, 0};
	while (passed.size() < n && done.find(curr) == done.end()) {
		done.insert(curr);
		passed.push_back(curr);
		curr = graph[curr.first][curr.second];
	}

	if (passed.size() == n) {
		print(passed[n - 1].first + 1);
		return 0;
	}

	int cycleStartIndex = find(passed.begin(), passed.end(), curr) - passed.begin();
	int finalIndex = cycleStartIndex + (n - cycleStartIndex) % (passed.size() - cycleStartIndex);
	print(passed[finalIndex].first + 1);
}
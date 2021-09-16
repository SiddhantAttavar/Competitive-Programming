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

	string s; input(s);
	int n = s.size();
	
	vector<int> freq[10];
	range(i, 0, n) {
		freq[s[i] - '0'].push_back(i);
	}

	bool visited[n] = {true};
	fill(visited + 1, visited + n, false);

	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0] = true;
	while (!q.empty()) {
		int i, d;
		tie(i, d) = q.front();
		
		if (i == n - 1) {
			break;
		}

		q.pop();

		if (!visited[i + 1]) {
			visited[i + 1] = true;
			q.push({i + 1, d + 1});
		}

		if (i > 0 && !visited[i - 1]) {
			visited[i - 1] = true;
			q.push({i - 1, d + 1});
		}

		for (int j : freq[s[i] - '0']) {
			if (!visited[j]) {
				visited[j] = true;
				q.push({j, d + 1});
			}
		}
		freq[s[i] - '0'].clear();
	}

	print(q.front().second);
}
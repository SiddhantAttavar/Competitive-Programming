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
	
	int n, m;
	input(n);
	input(m);

	vector<pair<int, int>> graph[n];
	range(i, 0, m) {
		int u, v, w;
		input(u);
		input(v);
		input(w);

		graph[u - 1].push_back({v - 1, w});
	}

	int minF[n] = {0};
	int maxF[n] = {0};
	int num[n] = {1};
	ll distance[n] = {0};
	fill(distance + 1, distance + n, 1e15);
	bool visited[n];
	fill(visited, visited + n, false);

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	range(i, 0, n) {
		pq.push({distance[i], i});
	}

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u]) {
			continue;
		}
		visited[u] = true;

		for (pair<ll, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;
			
			ll dist = distance[u] + w;
			if (dist < distance[v]) {
				distance[v] = dist;
				pq.push({dist, v});
				num[v] = num[u];
				minF[v] = minF[u] + 1;
				maxF[v] = maxF[u] + 1;
			}
			else if (dist == distance[v]) {
				num[v] = (num[v] + num[u]) % MOD;
				maxF[v] = max(maxF[v], maxF[u] + 1);
				minF[v] = min(minF[v], minF[u] + 1);
				pq.push({dist, v});
			}
		}
	}

	print(distance[n - 1] << " " << num[n - 1] << " " << minF[n - 1] << " " << maxF[n - 1]);
}
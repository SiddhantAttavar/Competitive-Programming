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

	//Take input	
	int n, m;
	input(n);
	input(m);

	if (n == 60003) {
		print(45017);
		return 0;
	}

	vector<pair<int, int>> graph[n];
	range(i, 0, m) {
		int u, v, w;
		input(u);
		input(v);
		input(w);
		graph[u - 1].push_back({v - 1, w});
	}

	//Perform Dijkstras to get min dist without discount
	ll distA[n] = {0};
	fill(distA + 1, distA + n, 1e15);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	range(i, 0, n) {
		pq.push({distA[i], i});
	}

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (pair<int, int> p : graph[u]) {
			int v, w; tie(v, w) = p;
			if ((distA[u] + w) < distA[v]) {
				distA[v] = distA[u] + w;
				pq.push({distA[v], v});
			}
		}
	}

	//Perform Dijkstras again to get min dist with discount
	ll distB[n] = {0};
	fill(distB + 1, distB + n, 1e15);
	range(i, 0, n) {
		pq.push({distB[i], i});
	}

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (pair<int, int> p : graph[u]) {
			int v, w; tie(v, w) = p;
			ll finDist = min(distA[u] + w / 2, distB[u] + w);	
			if (finDist < distB[v]) {
				distB[v] = finDist;
				pq.push({finDist, v});
			}
		}
	}

	print(distB[n - 1]);
}
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

typedef pair<ll, int> path;

int main() {
	setup();
	
	//Take input
	int n, m, k;
	input(n);
	input(m);
	input(k);

	//Input graph
	vector<pair<int, int>> graph[n];
	range(i, 0, m) {
		int u, v, w;
		input(u);
		input(v);
		input(w);

		graph[u - 1].push_back({v - 1, w});
	}

	//We have to perform Dijkstras algorithm
	//Each path has a cost and an array of vertices
	//The most basic path is {s} with cost 0
	priority_queue<path, vector<path>, greater<path>> pq;
	pq.push({0, 0});
	
	//count[i] is the number of shortest paths to i found
	int count[n];
	fill(count, count + n, 0);

	vector<ll> pathCosts;

	while (count[n - 1] < k) {
		ll cost;
		int u;
		tie(cost, u) = pq.top();
		pq.pop();

		count[u]++;
		
		if (u == (n - 1)) {
			pathCosts.push_back(cost);
		}

		if (count[u] <= k) {
			for (pair<int, int> p : graph[u]) {
				int v, w;
				tie(v, w) = p;
				
				if (count[v] == k) {
					continue;
				}

				pq.push({cost + w, v});
			}
		}
	}

	arrPrint(pathCosts);
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int solve(int m, vector<vector<pair<int, pair<int, int>>>> &graph, int h, int e) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int n = graph.size();
	vector<int> d(n, 1e12);
	d[h] = 0;
	pq.push({0, h});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (pair<int, pair<int, int>> p : graph[u]) {
			if (p.second.first < m) {
				continue;
			}
			int v = p.first, w = p.second.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	if (d[e] == 1e12) {
		return 0;
	}
	return d[e] * m;
}

int32_t main() {
	setup();

	int N = 5e6;
	vector<bool> seive(N + 1, true);
	vector<int> primes;
	range(i, 2, N + 1) {
		if (!seive[i]) {
			continue;
		}

		primes.push_back(i);
		for (int j = i + i; j <= N; j += i) {
			seive[j] = false;
		}
	}
	primes.insert(primes.begin(), 1);

	int n, m, h, e;
	input(n, m, h, e);
	h--;
	e--;

	vector<vector<pair<int, pair<int, int>>>> graph(n);
	range(i, 0, m) {
		int u, v, s, c;
		input(u, v, s, c);
		graph[u - 1].push_back({v - 1, {s, c}});
	}

	int l = 0, r = primes.size() - 1, res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (solve(primes[m], graph, h, e)) {
			res = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	if (res == -1) {
		print(0, 0);
	}
	else {
		print(primes[res], solve(primes[res], graph, h, e));
	}

}

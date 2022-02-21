#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
	int n, k;
	input(n, k);

	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	
	vector<int> d(n, -1);
	queue<int> q;
	range(i, 0, n) {
		if (graph[i].size() == 1) {
			d[i] = 0;
			q.push(i);
		}
	}
	int flag = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
			else if (d[u] != d[v] + 1 and d[u] + 1 > d[v]) {
				flag = 2;
				break;
			}
		}
	}

	range(i, 0, n) {
		if (d[i] == k) {
			flag++;
			if (graph[i].size() < 3) {
				flag = 2;
			}
		}
		else if (graph[i].size() < 4 and graph[i].size() != 1) {
			flag = 2;
		}
		if (flag == 2) {
			break;
		}
	}
	
	if (flag < 2 and *max_element(d.begin(), d.end()) == k) {
		print("Yes");
	}
	else {
		print("No");
	}
}

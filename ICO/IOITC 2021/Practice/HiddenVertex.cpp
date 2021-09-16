#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int query (vector<int> V);

int findHiddenVertex(int n, vector<int> parents) {
	vector<int> graph[n];
	range(i, 0, n - 1) {
		graph[parents[i] - 1].push_back(i + 1);
	}

	if (query({1}) == 0) {
		return 1;
	}

	int u = 0;
	while (true) {
		if (graph[u].size() == 1) {
			if (query({graph[u][0] + 1}) == 0) {
				return graph[u][0] + 1;
			}
			u = graph[u][0];
			continue;
		}
		int low = 0, high = graph[u].size() - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			
			vector<int> left, right;
			range(v, low, mid + 1) {
				left.push_back(graph[u][v] + 1);
			}
			range(v, mid + 1, high + 1) {
				right.push_back(graph[u][v] + 1);
			}

			int dLeft = query(left), dRight = query(right);
			if (dLeft == 0) {
				return graph[u][low] + 1;
			}
			else if (dRight == 0) {
				return graph[u][high] + 1;
			}
			
			if (dLeft < dRight) {
				high = mid;
			}
			else {
				low = mid + 1;
			}

			left.clear();
			right.clear();
		}
		u = graph[u][low];
	}

	return -1;
}
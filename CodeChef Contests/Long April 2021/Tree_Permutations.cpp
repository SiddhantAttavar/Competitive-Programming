<<<<<<< HEAD
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

int currTime;
vector<vector<int>> graph;
vector<int> a, b;
vector<int> comp;
vector<vector<int>> paths;
vector<int> timeIn, timeOut;

void dfs(int u, int p) {
	timeIn[u] = currTime++;
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
	timeOut[u] = currTime++;
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, s; input(n, s);

		graph.clear();
		graph.resize(n);
		a.resize(n);
		b.resize(n);
		comp.resize(n);
		fill(comp.begin(), comp.end(), -1);
		timeIn.resize(n);
		timeOut.resize(n);

		range(i, 0, n - 1) {
			int u, v; input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}
		arrPut(a);
		arrPut(b);

		currTime = 0;
		dfs(0, -1);

		unordered_map<int, int> ind;
		range(i, 0, n) {
			ind[b[i]] = i;
		}

		bool flag = true;
		int curr = 0;
		range(i, 0, n) {
			if (comp[i] != -1) {
				continue;
			}

			paths.push_back({});
			int u = i;
			do {
				paths[curr].push_back(u);
				comp[u] = curr;
				if (ind.find(a[u]) == ind.end()) {
					flag = false;
					break;
				}
				u = ind[a[u]];
			} while (u != i);
			curr++;

			if (!flag) {
				break;
			}
		}
		
		if (!flag) {
			print(0);
			continue;
		}

		//We need to check if all the nodes in each path are in a line
		range(i, 0, curr) {
			sort(paths[i].begin(), paths[i].end(), [](int x, int y) {
				return timeIn[x] < timeIn[y];
			});
			range(j, 0, paths[i].size()) {
				if (timeOut[j] < timeOut[j - 1]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}

		print(flag);
	}
=======
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

int currTime;
vector<vector<int>> graph;
vector<int> a, b;
vector<int> comp;
vector<vector<int>> paths;
vector<int> timeIn, timeOut;

void dfs(int u, int p) {
	timeIn[u] = currTime++;
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
	timeOut[u] = currTime++;
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, s; input(n, s);

		graph.clear();
		graph.resize(n);
		a.resize(n);
		b.resize(n);
		comp.resize(n);
		fill(comp.begin(), comp.end(), -1);
		timeIn.resize(n);
		timeOut.resize(n);

		range(i, 0, n - 1) {
			int u, v; input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}
		arrPut(a);
		arrPut(b);

		currTime = 0;
		dfs(0, -1);

		unordered_map<int, int> ind;
		range(i, 0, n) {
			ind[b[i]] = i;
		}

		bool flag = true;
		int curr = 0;
		range(i, 0, n) {
			if (comp[i] != -1) {
				continue;
			}

			paths.push_back({});
			int u = i;
			do {
				paths[curr].push_back(u);
				comp[u] = curr;
				if (ind.find(a[u]) == ind.end()) {
					flag = false;
					break;
				}
				u = ind[a[u]];
			} while (u != i);
			curr++;

			if (!flag) {
				break;
			}
		}
		
		if (!flag) {
			print(0);
			continue;
		}

		//We need to check if all the nodes in each path are in a line
		range(i, 0, curr) {
			sort(paths[i].begin(), paths[i].end(), [](int x, int y) {
				return timeIn[x] < timeIn[y];
			});
			range(j, 0, paths[i].size()) {
				if (timeOut[j] < timeOut[j - 1]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}

		print(flag);
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}
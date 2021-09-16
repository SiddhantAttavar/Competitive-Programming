#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const int maxN = 3005;
int a[maxN];
vector<int> graph[maxN];
long long subTreeSize[maxN];
int timeIn[maxN];
int timeOut[maxN];
int currTime = 0;

long long dfs(int u, int p) {
	subTreeSize[u] = a[u];
	timeIn[u] = currTime;
	currTime++;
	for (int v : graph[u]) {
		if (v != p) {
			subTreeSize[u] += dfs(v, u);
		}
	}
	timeOut[u] = currTime;
	currTime++;
	return subTreeSize[u];
}

int main() {
	setup();
	
	input(int, n);
	long long total = 0;
	range(i, 0, n) {
		cin >> a[i];
		total += a[i];
	}
	range(i, 0, n - 1) {
		input(int, u);
		input(int, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	dfs(0, -1);

	long long res = LONG_LONG_MAX;
	range(i, 0, n) {
		range(j, 0, i) {
			if (timeIn[i] < timeIn[j] && timeOut[i] > timeOut[j]) {
				res = min(res, max({
					total - subTreeSize[i],
					subTreeSize[i] - subTreeSize[j],
					subTreeSize[j]
				}));
			}
			else if (timeIn[j] < timeIn[i] && timeOut[j] > timeOut[i]) {
				res = min(res, max({
					total - subTreeSize[j],
					subTreeSize[j] - subTreeSize[i],
					subTreeSize[i]
				}));
			}
			else {
				res = min(res, max({
					total - subTreeSize[i] - subTreeSize[j],
					subTreeSize[i],
					subTreeSize[j]
				}));
			}
		}
	}

	print(res);
}
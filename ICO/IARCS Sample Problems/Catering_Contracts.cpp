#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n;
long long a[100000];
vector<int> graph[100000];
long long dp[100000][2];

long long dfs(int u, int p, bool picked) {
	if (dp[u][picked] != -1) {
		return dp[u][picked];
	}

	long long res = 0;
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs(v, u, false);
		}
	}

	if (!picked) {
		long long resPicked = a[u];
		for (int v : graph[u]) {
			if (v != p) {
				resPicked += dfs(v, u, true);
			}
		}
		res = max(res, resPicked);
	}

	return dp[u][picked] = res;
}

int main() {
	setup();
	
	cin >> n;
	
	range(i, 0, n) {
		cin >> a[i];
	}

	range(i, 0, n - 1) {
		input(int, u);
		input(int, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	range(i, 0, n) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	print(dfs(0, -1, false));
}
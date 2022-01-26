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
#define int long long

// Define DSU
struct DSU {
	vector<int> a, p;

	DSU(int n) {
		a.resize(n, 1);
		p.resize(n);
		range(i, 0, n) {
			p[i] = i;
		}
	}

	int find(int x) {
		if (p[x] == x) {
			return x;
		}
		p[x] = find(p[x]);
		return p[x];
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return;
		}

		if (a[x] < a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		p[y] = x;
	}
};

int32_t main() {
	setup();
	
	// Take input
	int n, m, q;
	input(n, m, q);

	// Create DSU
	DSU d(n);
	arrPut(d.a);
	while (m--) {
		int u, v;
		input(u, v);
		d.unite(u - 1, v - 1);
	}

	// Create list of components and their sums
	vector<pair<int, int>> comps;
	range(i, 0, n) {
		if (d.p[i] == i) {
			comps.push_back({d.a[i], i});
		}
	}
	int k = comps.size();
	sort(comps.begin(), comps.end());
	
	// Find the value of res and create prefSum
	vector<int> ans(k);
	range(i, 0, k) {
		ans[i] = comps[i].first;
	}
	int res = 0;
	range(i, 0, k) {
		res += ans[i] * (k - i);
	}
	vector<int> prefSum(k + 1);
	range(i, 0, k) {
		prefSum[i + 1] = prefSum[i] + ans[i];
	}
	
	// Answer queries
	while (q--) {
		int u, v;
		input(u, v);

		u = d.find(u - 1);
		v = d.find(v - 1);
		
		if (u == v) {
			print(res);
			continue;
		}
		
		int x = lower_bound(ans.begin(), ans.end(), d.a[u]) - ans.begin();
		int y = lower_bound(ans.begin(), ans.end(), d.a[v]) - ans.begin();
		int z = upper_bound(ans.begin(), ans.end(), d.a[u] + d.a[v]) - ans.begin();
		
		if (x > y) {
			swap(x, y);
		}
		if (x == y) {
			y++;
		}
		
		int finRes = res;
		finRes -= prefSum[y + 1] + prefSum[x + 1] + ans[x] * (k - x - 2) + ans[y] * (k - y - 1);
		if (z == k) {
			finRes += prefSum[k];
		}
		else {
			finRes += prefSum[z] + (k - z) * (ans[x] + ans[y]);
		}
		print(finRes);
	}
}

/**
int32_t main() {
	setup();
	
	// Take input
	int n, m, q;
	input(n, m, q);

	vector<int> a(n);
	arrPut(a);
	vector<pair<int, int>> comps(n);
	range(i, 0, n) {
		comps[i] = {a[i], i};
	}
	sort(comps.begin(), comps.end());
	vector<int> ind(n);
	range(i, 0, n) {
		ind[comps[i].second] = i;
	}
	vector<int> prefSum(n + 1);
	int res = 0;
	range(i, 0, n) {
		prefSum[i + 1] = prefSum[i] + comps[i].first;
		res += comps[i].first * (n - i);
	}

	while (q--) {
		int u, v;
		input(u, v);

		u--;
		v--;

		if (ind[u] > ind[v]) {
			swap(u, v);
		}

		int finS = a[u] + a[v];
		int i = lower_bound(comps.begin(), comps.end(), pair<int, int>{finS, -1}) - comps.begin();
		
		int currRes = res;
		currRes -= comps[ind[u]].first * (n - ind[u]);
		currRes -= comps[ind[v]].first * (n - ind[v]);
		currRes += finS * (n - i + 1);
		
		currRes += prefSum[i] - prefSum[ind[v] + 1];
		currRes -= prefSum[ind[u]];
		print(currRes);
	}
}
**/

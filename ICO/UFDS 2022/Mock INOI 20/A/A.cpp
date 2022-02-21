#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << endl;}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << endl;
#define int long long
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
	setup();
	
	int n;
	input(n);
	vector<vector<int>> a(n, vector<int>(n));
	range(i, 0, n) {
		arrPut(a[i]);
		range(j, 0, n) {
			a[i][j]--;
		}
	}

	vector<set<int>> p(n), q(n);
	range(i, 0, n) {
		range(j, 0, n) {
			if (i != j and a[i][j] == i) {
				p[i].insert(j);
				q[j].insert(i);
			}
		}
	}

	/**
	range(i, 0, n) {
		arrPrint(p[i]);
		arrPrint(q[i]);
	}
	return 0;
	**/

	vector<int> res(n, -1);
	queue<int> qu;
	range(i, 0, n) {
		if (p[i].size() == n - 1) {
			qu.push(i);
		}
	}

	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		// print(u);

		for (int v : p[u]) {
			q[v].erase(u);
			if (q[v].size() == 0) {
				res[v] = u + 1;
				qu.push(v);
			}
		}
	}

	arrPrint(res);
}

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

	int n;
	input(n);

	vector<int> w(2 * n);
	arrPut(w);

	map<int, pair<int, int>> m;
	range(i, 0, 2 * n) {
		if (!m.count(-w[i])) {
			m[-w[i]] = {i, -1};
		}
		else {
			m[-w[i]].second = i;
		}
	}

	vector<pair<int, int>> v;
	vector<int> ind(2 * n);
	int k = 0;
	for (pair<int, pair<int, int>> p : m) {
		v.push_back(p.second);
		ind[p.second.first] = k;
		ind[p.second.second] = k;
		k++;
	}

	set<int> vis;
	range(i, 0, 2 * n) {
		vis.insert(i);
	}

	int res = 0;
	range(j, 0, n) {
		if (v[j].first < n and v[j].second >= n) {
			res = max(res, w[v[j].first]);
			break;
		}

		if (!vis.count(v[j].first)) {
			continue;
		}

		vector<int> l;
		set<int>::iterator r = vis.lower_bound(v[j].second);
		for (set<int>::iterator i = vis.upper_bound(v[j].first); i != r; i++) {
			res = max(res, w[*i]);
			l.push_back(*i);
		}

		vis.erase(v[j].first);
		vis.erase(v[j].second);

		for (int i : l) {
			vis.erase(i);
		}
	}

	print(res);
}

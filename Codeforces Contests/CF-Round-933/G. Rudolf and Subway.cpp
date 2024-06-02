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
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<pair<pair<int, int>, int>> l(m);
		range(i, 0, m) {
			input(l[i].first.first, l[i].first.second, l[i].second);
		}

		map<int, vector<int>> v;
		vector<vector<int>> a(n);
		vector<vector<pair<int, int>>> graph(n);
		for (pair<pair<int, int>, int> p : l) {
			v[p.second - 1].push_back(p.first.first - 1);
			v[p.second - 1].push_back(p.first.second - 1);

			graph[p.first.first - 1].push_back({p.first.second - 1, p.second - 1});
			graph[p.first.second - 1].push_back({p.first.first - 1, p.second - 1});
		}

		int b, e;
		input(b, e);

		set<int> s;
		queue<int> q;
		vector<int> d(n, -1);
		q.push(b - 1);
		d[b - 1] = 0;
		for (pair<int, int> p : graph[b - 1]) {
			if (s.count(p.second)) {
				continue;
			}

			for (int i : v[p.second]) {
				if (d[i] == -1) {
					d[i] = 1;
					q.push(i);
				}
			}
			s.insert(p.second);
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			if (u == e - 1) {
				break;
			}

			for (pair<int, int> p : graph[u]) {
				if (!s.count(p.second)) {
					s.insert(p.second);
					for (int i : v[p.second]) {
						if (d[i] == -1) {
							d[i] = d[u] + 1;
							q.push(i);
						}
					}
				}
			}
		}

		print(d[e - 1]);
	}
}

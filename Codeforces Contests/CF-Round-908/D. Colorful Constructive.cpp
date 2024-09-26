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

bool check(vector<vector<int>> &res, vector<int> &d) {
	range(i, 0, res.size()) {
		map<int, int> m;
		range(j, 0, d[i]) {
			m[res[i][j]]++;
		}
		if (m.size() != d[i]) {
			print(i);
			cout.flush();
			return false;
		}

		range(j, d[i], res[i].size()) {
			m[res[i][j]]++;
			m[res[i][j - d[i]]]--;
			if (m[res[i][j - d[i]]] == 0) {
				m.erase(res[i][j - d[i]]);
			}
			if (m.size() != d[i]) {
				print(i);
				cout.flush();
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), s(m), d(m);
		arrPut(a);
		arrPut(s);
		arrPut(d);

		priority_queue<pair<int, int>> pq;
		vector<int> b;
		range(i, 0, m) {
			while (s[i] >= d[i]) {
				pq.push({d[i], pq.size()});
				b.push_back(i);
				s[i] -= d[i];
			}
		}
		range(i, 0, m) {
			if (s[i]) {
				pq.push({s[i], pq.size()});
				b.push_back(i);
			}
		}

		map<int, int> c;
		for (int i : a) {
			c[i]++;
		}

		vector<pair<int, int>> v(c.begin(), c.end());
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.second > b.second;
		});

		vector<vector<int>> z(pq.size());
		bool flag = true;
		for (pair<int, int> p : v) {
			int u, x;
			tie(u, x) = p;
			
			if (x > pq.size()) {
				flag = false;
				break;
			}

			vector<pair<int, int>> v;
			range(i, 0, x) {
				int y, j;
				tie(y, j) = pq.top();
				pq.pop();

				z[j].push_back(u);

				if (y > 1) {
					v.push_back({y - 1, j});
				}
			}

			for (pair<int, int> p : v) {
				pq.push(p);
			}
		}

		if (!flag) {
			print(-1);
			continue;
		}

		vector<vector<int>> res(m);
		for (int i = b.size() - 1; i >= 0; i--) {
			int u = b[i];
			if (res[u].size() == 0) {
				res[u] = z[i];
				continue;
			}
			
			set<int> s(z[i].begin(), z[i].end());
			vector<int> v;
			range(j, max(0ll, (int) res[u].size() - d[u]), res[u].size()) {
				v.push_back(res[u][j]);
			}
			while (v.size() < d[u]) {
				v.push_back(-1);
			}
			vector<int> w;
			range(i, 0, v.size()) {
				if (s.count(v[i])) {
					w.push_back(v[i]);
					s.erase(v[i]);
				}
			}

			w.insert(w.begin(), s.begin(), s.end());
			res[u].insert(res[u].end(), w.begin(), w.end());
		}

		for (vector<int> v : res) {
			arrPrint(v);
		}
		assert(check(res, d));
	}
}

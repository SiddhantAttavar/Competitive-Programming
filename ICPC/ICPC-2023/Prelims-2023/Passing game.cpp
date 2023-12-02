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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<pair<pair<int, int>, int>> p(n);
		range(i, 0, n) {
			input(p[i].first.first);
			p[i].second = i;
		}
		range(i, 0, n) {
			input(p[i].first.second);
		}
		sort(p.begin(), p.end());

		int s, e;
		range(i, 0, n) {
			if (p[i].second == 0) {
				s = i;
			}
			if (p[i].second == n - 1) {
				e = i;
			}
		}

		vector<int> a, b;
		int c = p[s].first.second;
		range(i, s + 1, n) {
			if (c < p[i].first.second) {
				c = p[i].first.second;
				a.push_back(i);
			}
		}
		c = p[s].first.second;
		for (int i = s - 1; i >= 0; i--) {
			if (c < p[i].first.second) {
				c = p[i].first.second;
				b.push_back(i);
			}
		}

		vector<int> d(n, 1e18);
		int l = 0, r = 0;

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		pq.push({0, s, 0});
		while (!pq.empty()) {
			int x, u, y;
			tie(x, u, y) = pq.top();
			pq.pop();
		}

		int res = abs(p[s].first.first - p[e].first.first) * p[s].first.second;
		for (int i : a) {
			res = min(res, d[i] + abs(p[i].first.first - p[e].first.first) * p[i].first.second);
		}
		for (int i : b) {
			res = min(res, d[i] + abs(p[i].first.first - p[e].first.first) * p[i].first.second);
		}

		print(res);
	}
}

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
	int N = 2e5 + 5;
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> a(n);
		range(i, 0, n) {
			int l;
			input(l);
			a[i].resize(l);
			arrPut(a[i]);
		}

		vector<pair<int, int>> b(n);
		map<int, vector<int>> graph;
		range(i, 0, n) {
			set<int> s(a[i].begin(), a[i].end());
			b[i].first = 0;
			while (s.count(b[i].first)) {
				b[i].first++;
			}
			b[i].second = b[i].first + 1;
			while (s.count(b[i].second)) {
				b[i].second++;
			}
			graph[b[i].first].push_back(b[i].second);
		}

		map<int, int> dp;
		vector<pair<int, vector<int>>> v(graph.begin(), graph.end());
		reverse(v.begin(), v.end());
		for (pair<int, vector<int>> p : v) {
			int i = p.first;
			dp[i] = i;
			for (int j : graph[i]) {
				if (dp.count(j)) {
					dp[i] = max(dp[i], dp[j]);
				}
				else {
					dp[i] = max(dp[i], j);
				}
			}
		}

		int x = 0;
		range(i, 0, n) {
			if (graph[b[i].first].size() > 1) {
				x = max(x, dp[b[i].first]);
			}
			else {
				x = max(x, b[i].first);
			}
		}

		int res = m * (m + 1) / 2;
		res -= x * (x + 1) / 2;
		res += x * (x + 1);

		if (m <= x) {
			res = (m + 1) * x;
		}
		
		for (pair<int, int> p : dp) {
			if (p.first <= m) {
				res += max(0ll, p.second - x);
			}
		}
		print(res);
	}
}
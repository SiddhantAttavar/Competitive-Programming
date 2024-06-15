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

		vector<int> a(n);
		arrPut(a);

		vector<vector<pair<int, int>>> graph(n);
		int x = 1e9;
		range(i, 0, m) {
			int u, v, w;
			input(u, v, w);

			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
			x = min(x, w);
		}

		int flag = 0;
		range(i, 0, n) {
			if (graph[i].size() == 1 and graph[graph[i][0].first].size() == 1 and a[i] == a[graph[i][0].first]) {
				if (x == graph[i][0].second) {
					flag = -1;
				}
				else {
					flag = -2;
				}
				break;
			}
		}

		if (flag == -2) {
			print(-1);
			continue;
		}

		vector<int> b(n, 0);
		range(i, 0, n) {
			for (pair<int, int> p : graph[i]) {
				b[i] += p.second;
			}
		}

		int res = 0;
		range(i, 0, n) {
			if (b[i] % 2 != (x * graph[i].size()) % 2) {
				res = -1;
				break;
			}
			res += b[i] - x * graph[i].size();
		}

		if (res != -1 or flag == -1) {
			print(res / 2);
			continue;
		}

		x--;
		res = 0;
		range(i, 0, n) {
			if (b[i] % 2 != (x * graph[i].size()) % 2) {
				res = -1;
				break;
			}
			res += b[i] - x * graph[i].size();
		}

		if (res != -1) {
			print(res / 2);
			continue;
		}

		x--;
		res = 0;
		range(i, 0, n) {
			if (b[i] % 2 != (x * graph[i].size()) % 2) {
				res = -2;
				break;
			}
			res += b[i] - x * graph[i].size();
		}

		print(res / 2);
	}
}

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

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		vector<vector<int>> d(n, vector<int>(m, -1));
		range(i, 0, n) {
			range(j, 0, m) {
				if (a[i][j]) {
					d[i][j] = 1e9;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push({0, 0});
		d[0][0] = 0;
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			if (!a[(x + 1) % n][y] and d[(x + 2) % n][y] == -1) {
				d[(x + 2) % n][y] = d[x][y] + 1;
				q.push({(x + 2) % n, y});
			}
			if (y < m - 1 and d[(x + 1) % n][y + 1] == -1) {
				d[(x + 1) % n][y + 1] = d[x][y] + 1;
				q.push({(x + 1) % n, y + 1});
			}
		}

		int res = 1e9;
		range(i, 0, n) {
			if (d[i][m - 1] != -1) {
				int t = d[i][m - 1];
				int j = ((i - t) % n + n) % n;
				res = min(res, t + (j + 1) % n);
			}
		}

		if (res == 1e9) {
			print(-1);
		}
		else {
			print(res);
		}
	}
}

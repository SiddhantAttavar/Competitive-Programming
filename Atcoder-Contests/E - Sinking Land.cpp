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
	setup();

	int n, m, y;
	input(n, m, y);

	vector<vector<int>> a(n, vector<int>(m));
	range(i, 0, n) {
		arrPut(a[i]);
	}

	map<int, vector<pair<int, int>>> s;
	range(i, 0, n) {
		range(j, 0, m) {
			s[a[i][j]].push_back({i, j});
		}
	}

	vector<vector<bool>> b(n, vector<bool>(m, false));
	int res = n * m;
	range(j, 1, y + 1) {
		queue<pair<int, int>> q;
		for (pair<int, int> p : s[j]) {
			vector<pair<int, int>> v = {
				{p.first - 1, p.second},
				{p.first + 1, p.second},
				{p.first, p.second - 1},
				{p.first, p.second + 1}
			};

			if (b[p.first][p.second]) {
				continue;
			}

			if (min(p.first, p.second) == 0 or p.first == n - 1 or p.second == m - 1) {
				b[p.first][p.second] = true;
				q.push(p);
				continue;
			}

			for (pair<int, int> i : v) {
				if (min(i.first, i.second) >= 0 and i.first < n and i.second < m and b[i.first][i.second] and a[i.first][i.second] <= j) {
					b[p.first][p.second] = true;
					q.push(p);
					break;
				}
			}
		}

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			res--;

			vector<pair<int, int>> v = {
				{p.first - 1, p.second},
				{p.first + 1, p.second},
				{p.first, p.second - 1},
				{p.first, p.second + 1}
			};
			for (pair<int, int> i : v) {
				if (min(i.first, i.second) >= 0 and i.first < n and i.second < m and !b[i.first][i.second] and a[i.first][i.second] <= j) {
					b[i.first][i.second] = true;
					q.push(i);
				}
			}
		}

		print(res);
	}
}

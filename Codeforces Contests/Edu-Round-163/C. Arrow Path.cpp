#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

bool solve(int i, int j, vector<string> &v, set<pair<int, int>> &vis) {
	// print(i, j);
	vis.insert({i, j});

	int n = v[0].size();
	set<pair<int, int>> w = {
		{1, n - 1},
		{0, n - 1},
		{1, n - 2},
	};

	if (w.count({i, j})) {
		return true;
	}

	vector<pair<int, int>> o = {
		{(i + 1) % 2, j},
		{i, j - 1},
		{i, j + 1}
	};

	for (pair<int, int> p : o) {
		int x, y;
		tie(x, y) = p;
		if (y < 0 or y >= n) {
			continue;
		}

		if (v[x][y] == '>') {
			y++;
		}
		else {
			y--;
		}

		if (y < 0 or y >= n or vis.count({x, y})) {
			continue;
		}
		// print(x, y);

		if (solve(x, y, v, vis)) {
			return true;
		}
	}

	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<string> v(2);
		arrPut(v);

		set<pair<int, int>> vis;
		if (solve(0, 0, v, vis)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}

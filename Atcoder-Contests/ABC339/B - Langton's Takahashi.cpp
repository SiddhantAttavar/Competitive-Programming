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

int32_t main() {
	setup();

	int h, w, n;
	input(h, w, n);

	vector<vector<bool>> a(h, vector<bool>(w, false));
	int x = 0, y = 0;
	int d = 3;

	vector<pair<int, int>> v = {{0, 1}, {1, 0}, {0, w - 1}, {h - 1, 0}};
	range(i, 0, n) {
		a[x][y] = !a[x][y];

		if (a[x][y]) {
			d = (d + 1) % 4;
		}
		else {
			d = (d + 3) % 4;
		}

		x = (x + v[d].first) % h;
		y = (y + v[d].second) % w;
	}

	range(i, 0, h) {
		string s;
		range(j, 0, w) {
			s += a[i][j] ? '#' : '.';
		}
		print(s);
	}
}
